#include <vector>
using namespace std;

//SEPARATE CHAINING
class MyHashSet {
private:
    static const int SIZE = 1000; // Size of the hash table
    vector<vector<int>> table; // Hash table with separate chaining

    int hash(int key) {
        return key % SIZE; // Hash function
    }
public:
    MyHashSet() : table(SIZE) {} // Initialize the hash table with empty chains

    void add(int key) {
        int index = hash(key);
        for (int k : table[index]) {
            if (k == key) return; // Key already exists
        }
        table[index].push_back(key); // Add key to the chain
    }

    void remove(int key) {
        int index = hash(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == key) {
                chain.erase(it); // Remove key from the chain
                return;
            }
        }
    }

    bool contains(int key) {
        int index = hash(key);
        for (int k : table[index]) {
            if (k == key) return true; // Key found
        }
        return false; // Key not found
    }
};