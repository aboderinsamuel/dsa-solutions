class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];

    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(const string& word, int i, TrieNode* node) {

        // Entire word has been processed.
        // Return true only if we're at the end of a valid word.
        if (i == word.length())
            return node->isWord;

        char c = word[i];

        // Normal character.
        if (c != '.') {

            int idx = c - 'a';

            // Character doesn't exist.
            if (!node->children[idx])
                return false;

            // Continue matching the rest of the word.
            return dfs(word, i + 1, node->children[idx]);
        }

        // Wildcard '.'
        // Try every possible child.
        for (int j = 0; j < 26; j++) {

            if (node->children[j] &&
                dfs(word, i + 1, node->children[j])) {

                return true;
                }
        }

        // No child matched.
        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {

        TrieNode* curr = root;

        for (char c : word) {

            int idx = c - 'a';

            if (!curr->children[idx])
                curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }

        curr->isWord = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};