//
// Created by samuel on 5/27/26.
//
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    pair<int, int> dfs(TreeNode* root)
    {
        if (!root)return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        //rob
        int rob = root->val + left.second + right.second;
        //skip
        int skip = max(left.first, left.second) + max(right.second, right.first);
        return {rob, skip};
    }
    int rob(TreeNode* root)
    {
        auto ans = dfs(root);
        return max(ans.first, ans.second);

    }
};