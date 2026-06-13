#include <vector>
#include <unordered_map>
using namespace std;

// Hashmap  + Doubly linked list = LRU Cache

struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        //bypass the middle or current node
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    //inserts node right after the dummy head
    void addToHead(Node* node) {
        Node* nextNode = head->next;

        node->next = nextNode;
        node->prev = head;

        //wire surroundings back to new node
        head->next = node;
        nextNode->prev = node;
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
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];

            removeNode(node);
            addToHead(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            removeNode(node);
            addToHead(node);
        }else {
            if (cache.size() == capacity) {
                Node* lruNode = tail->prev;
                cache.erase(lruNode->key);
                removeNode(lruNode);
                delete lruNode;
            }
            //Now, create the new node, add to map, and put at head;
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);
        }
    }
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */