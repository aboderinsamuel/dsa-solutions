//
// Created by samuel on 5/28/26.
//

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        //Base case: if root is null, or we found either p or q
        if(root == nullptr || root == p || root == q){
            return root;
        }

        //look for p and q in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //If p and q are found in different subtrees, the current root is the LCA
        if(left != nullptr && right != nullptr){
            return root;
        }
        //otherwise, return the non-null side (where both or one of the nodes were found)
        return left != nullptr ? left : right;
    }
};