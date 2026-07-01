//
// Created by samuel on 5/29/26.
//

#include <string>
#include <queue>
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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string res;
        serializeHelper(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        int pos = 0;
        return deserializeHelper(data, pos, INT_MIN, INT_MAX);
    }
private:
    void serializeHelper(TreeNode* node, string& res) {
        if (!node) return;
        res += to_string(node->val) + ",";
        serializeHelper(node->left, res);
        serializeHelper(node->right, res);
    }

    TreeNode* deserializeHelper(const string& data, int& pos, int lower, int upper) {
        if (pos >= data.size()) return nullptr;

        // Peek at the next value without consuming the main position pointer yet
        int tempPos = pos;
        int val = 0;
        bool isNegative = false;

        if (data[tempPos] == '-') {
            isNegative = true;
            tempPos++;
        }

        while (tempPos < data.size() && data[tempPos] != ',') {
            val = val * 10 + (data[tempPos] - '0');
            tempPos++;
        }
        if (isNegative) val = -val;

        // If the parsed value violates the BST bounds, this path naturally terminates
        if (val < lower || val > upper) {
            return nullptr;
        }

        // Value is valid, advance the main position pointer past the comma
        pos = tempPos + 1;

        TreeNode* node = new TreeNode(val);
        node->left = deserializeHelper(data, pos, lower, val);
        node->right = deserializeHelper(data, pos, val, upper);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;