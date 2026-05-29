//
// Created by samuel on 5/28/26.
//
#include <algorithm>
#include <climits>
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
    int ans = INT_MIN;
    int dfs(TreeNode* root)
    {
        if (!root)return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        //best path coming down
        ans = max(ans, root->val + left + right);

        //return best path ogin up
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        return ans;
    }

};