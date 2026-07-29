#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};