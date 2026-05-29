#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> height;
    unordered_map<int, int> answer;

    int getHeight(TreeNode* root){
        if(!root)return -1;

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return height[root->val] = 1 + max(left, right);
    }

    void dfs(TreeNode* root, int depth, int restHeight){
        if(!root)return;
        answer[root->val] = restHeight;

        int leftHeight = root->left ? height[root->left->val] : -1;

        int rightHeight = root->right ? height[root->right->val] : -1;

        //go left
        dfs(root->left, depth + 1, max(restHeight, depth + 1 + rightHeight));

        //go right
        dfs(root->right, depth + 1, max(restHeight, depth + 1 + leftHeight));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        getHeight(root);
        dfs(root, 0, 0);
        vector<int> res;
        for(int q : queries){
            res.push_back(answer[q]);
        }
        return res;
    }
};
//step ! : computer maximum height for each node's subtree
// step2 : best height possible WITHOUT this subtree