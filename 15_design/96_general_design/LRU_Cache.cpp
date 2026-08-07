#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;   // key -> node pointer
    Node* head;  // dummy head (most recently used side)
    Node* tail;  // dummy tail (least recently used side)

    // Remove a node from its current position in the list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert a node right after head (mark as most recently used)
    void insertAtFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        remove(node);
        insertAtFront(node);   // move to most recently used
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key exists: update value, move to front
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insertAtFront(node);
            return;
        }

        if ((int)mp.size() == capacity) {
            // Evict least recently used = node just before tail
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);
        insertAtFront(node);
        mp[key] = node;
    }
};