//
// Created by samuel on 5/28/26.
//
#include <queue>
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
    int maxLevelSum(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int bestLevel = 1;
        long long bestSum = LONG_MIN;

        while (!q.empty())
        {
            int size = q.size();
            long long sum = 0;

            for (int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > bestSum)
            {
                bestSum = sum;
                bestLevel = level;
            }
            level++;
        }
        return bestLevel;
    }
};