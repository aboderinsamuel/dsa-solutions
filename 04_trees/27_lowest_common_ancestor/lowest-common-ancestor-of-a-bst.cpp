//
// Created by samuel on 5/28/26.
//
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(!root || root == p || root == q){
            return root;
        }

        //search bothsides
        TreeNode* left = lowestCommonAncestor(root->left , p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //bothsides found sth
        if(left && right){
            return root;
        }
        //return non-null side
        return left ? left : right;
    }
};
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//optimal
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {

            // both smaller
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }

            // both greater
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }

            // split point
            else {
                return root;
            }
        }

        return nullptr;
    }
};
