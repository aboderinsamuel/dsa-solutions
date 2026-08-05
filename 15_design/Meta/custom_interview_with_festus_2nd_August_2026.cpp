// You're asked to walk around the outside of the tree in two parts:
//
// Stand on the left side of the tree.
// Record the nodes you can see (the left view).
// Output them from bottom to top.
// Then stand on the right side of the tree.
// Record the nodes you can see (the right view).
// Output them from top to bottom.
// Don't repeat the root, since it was already included from the left side.
//
// Finally, concatenate the two sequences.
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<int> walkBothSides(TreeNode* root) {
        if (!root) return {};
        vector<int> leftView;
        vector<int> rightView;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i=0; i<levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (i == 0) leftView.push_back(curr->val); // First node
                if (i == levelSize - 1) rightView.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        reverse(leftView.begin(), leftView.end()); // Bottom to top for left view
        for (int i=1; i<rightView.size(); i++) { // Start from 1 to avoid root duplication
            leftView.push_back(rightView[i]);
        }
        return leftView;
    }
};