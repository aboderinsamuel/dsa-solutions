#include <vector>
using namespace std;

class MyHashSet {
    vector<bool> exists;
public:
    MyHashSet() : exists(1000001, false) {}
    void add(int key) {
        exists[key] = true;
    }
    void remove(int key) {
        exists[key] = false;
    }
    bool contains(int key) {
        return exists[key];
    }
};