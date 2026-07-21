#include <unordered_map>
#include <string>
#include <vector>

using namespace std;
class Solution {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word; // Store the complete word at the end node
    };
    //reason for trienode as opposed to word search 1:


};