//
// Created by samuel on 5/29/26.
//

#include <string>
#include <queue>
#include <sstream>
#include <climits>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
class Codec {
public:

    void serializeDFS(TreeNode* root, string& s) {

        if (!root) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeDFS(root->left, s);
        serializeDFS(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s;

        serializeDFS(root, s);

        return s;
    }

    TreeNode* deserializeDFS(vector<string>& nodes, int& idx) {

        if (nodes[idx] == "N") {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx++]));

        root->left = deserializeDFS(nodes, idx);
        root->right = deserializeDFS(nodes, idx);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string token;

        stringstream ss(data);

        while (getline(ss, token, ',')) {

            if (!token.empty())
                nodes.push_back(token);
        }

        int idx = 0;

        return deserializeDFS(nodes, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;