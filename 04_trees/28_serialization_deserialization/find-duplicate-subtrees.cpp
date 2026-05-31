//
// Created by samuel on 5/31/26.
//

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<string, int> tripletToID;
    unordered_map<int, int> idCount;
    vector<TreeNode*> duplicates;

    int traverse(TreeNode* node){
        if(!node) return 0;
        //1.Post order traversal: Process the children first
        int leftID = traverse(node->left);
        int rightID = traverse(node->right);

        //2.Rep the current subtree as a short string triplet
        string triplet = to_string(node->val) + "," + to_string(leftID) + "," + to_string(rightID);

        //3. If this is a new structure, generate a new ID for it
        if(!tripletToID.count(triplet)){
            tripletToID[triplet] = tripletToID.size() + 1;
        }
        int currentID = tripletToID[triplet];

        //4. increment the count for this specific subtree ID
        idCount[currentID]++;

        //5. If we hit exactly 2, we found a duplicate!
        if(idCount[currentID] == 2){
            duplicates.push_back(node);
        }
        return currentID;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return duplicates;
    }
};