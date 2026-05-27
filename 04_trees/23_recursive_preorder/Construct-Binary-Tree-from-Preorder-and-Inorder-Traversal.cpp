//
// Created by samuel on 5/27/26.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace  std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

class Solution
{
    public:
    unordered_map<int, int> inIndex;
    int preIdx = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right)
    {
        if(left > right)return nullptr;

        //pick from preorder
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        //find position in inorder
        int mid = inIndex[rootVal];

        //build left subtree
        root->left = build(preorder, inorder, left, mid - 1);
        //build right subtree
        root->right = build(preorder, inorder, mid + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for(int i=0; i<inorder.size(); ++i)inIndex[inorder[i]] = i;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};

//TEST===============================================================================================================
void printPreorder(TreeNode* root)
{
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(TreeNode* root)
{
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printLevelOrder(TreeNode* root)
{
    if (!root)
    {
        cout << "Empty tree\n";
        return;
    }

    vector<TreeNode*> q;
    int front = 0;
    q.push_back(root);

    while (front < (int)q.size())
    {
        TreeNode* node = q[front++];
        cout << node->val << " ";

        if (node->left) q.push_back(node->left);
        if (node->right) q.push_back(node->right);
    }
    cout << "\n";
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

    cout << "Preorder of constructed tree: ";
    printPreorder(root);
    cout << "\n";

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << "\n";

    cout << "Level-order of constructed tree: ";
    printLevelOrder(root);

    return 0;
}