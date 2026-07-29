#include <vector>
#include <list>
using namespace std;

class MyHashMap{
private:
    static const int SIZE = 1009;
    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return key % SIZE;
    }
public:
    MyHashMap() : table(SIZE) {}

    void put(int key, int value) {
        int index = hash(key);
        for (auto& p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    int get(int key) {
        int index = hash(key);
        for (const auto& p : table[index]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1; // Key not found
    }

    void remove(int key) {
        int index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};