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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";

        //preorder traversal: root, left, right
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserializeHelper(data, index);
    }
private:
    TreeNode* deserializeHelper(const string& data, int& index){
        //find the next value
        if(index >= data.size()) return nullptr;

        //find the delimeter position
        int delimiterPos = data.find(',', index);
        string token = data.substr(index, delimiterPos-index);
        index = delimiterPos + 1;

        //handle null nodes
        if(token == "#") return nullptr;

        //create node with value
        TreeNode* node = new TreeNode(stoi(token));

        //recursively build left and right subtrees
        node->left = deserializeHelper(data, index);
        node->right = deserializeHelper(data, index);
        return node;

    }
};