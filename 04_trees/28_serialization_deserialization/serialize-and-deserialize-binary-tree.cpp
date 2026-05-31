//
// Created by samuel on 5/29/26.
//
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:
    string serialize(TreeNode* root) {}
    TreeNode* deserialize(string data) {}
private:
    //Helper function for recursive serialization
    void serialHelper(TreeNode* node, ostringstream& out)
    {
        if (!node)
        {
            out << "N ";
            return;
        }
        out << node->val << " ";
        serialHelper(node->left, out);
        serialHelper(node->right, out);
    }
    //Helper function for recursive desrialization
    TreeNode* deserializeHelper(istringstream& in)
    {
        string val;
        in >> val;
        if (val == "N")
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};
