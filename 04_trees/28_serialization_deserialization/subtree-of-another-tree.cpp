//
// Created by samuel on 5/29/26.
//
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
private:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        //if bothsides are null, they match
        if (p == nullptr && q == nullptr)  return true;
        //if only one is null, or their calues differ, they dont match
        if (p == nullptr || q == nullptr || p->val != q->val) return false;
        //otherwise, check the subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
public:
    bool isSubTree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr) return false;

        if (isSameTree(root, subRoot)) return true;

        return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
    }
};