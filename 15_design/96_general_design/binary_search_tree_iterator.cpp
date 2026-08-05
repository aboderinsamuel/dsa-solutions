#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class BSTIterator {
private:
    // stack stores the path of the nodes that are not yet visited
    stack<TreeNode*> st;
    // push all the left children of the node into the stack
    // WHY? : In inorder traversal: LEFT -> ROOT -> RIGHT
    // The leftmost node is always the next smallest value
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
public:
    // Constructor: initialize the iterator with the root of the BST
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    int next() {
        // The top of the stack is the next smallest element
        TreeNode* node = st.top();
        st.pop();
        // If the node has a right child, push all its left children into the stack
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }
    bool hasNext() {
        return !st.empty();
    }

};
