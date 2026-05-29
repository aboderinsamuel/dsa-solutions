//
// Created by samuel on 5/27/26.
//
#include <algorithm>
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
class Solution
{
public:
    vector<int> sizes;
    pair<bool, int> dfs(TreeNode* root)
    {
        if (!root)return{true, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        bool isPerfect = left.first && right.first && (left.second == right.second);
        int height = 1 + left.second;
        if (isPerfect)
        {
            int size = 1 << height;
            sizes.push_back(size);
        }
        return {isPerfect, height};
    }
    int kthLargestSize(TreeNode* root, int k)
    {
        dfs(root);
        sort(sizes.rbegin(), sizes.rend());
        if (k > sizes.size())return -1;
        return sizes[k-1];
    }
};