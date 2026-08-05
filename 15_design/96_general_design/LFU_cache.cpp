/*
 * ============================================================================
 * LFU Cache – Least Frequently Used eviction policy
 * ============================================================================
 * First principles:
 *   • We need O(1) get() and put().
 *   • We must track the frequency of each key (how many times it has been accessed).
 *   • When the cache is full, we evict the item with the lowest frequency.
 *   • If there are multiple items with the same lowest frequency, we evict the
 *     least recently used among them (FIFO within that frequency group).
 *
 * Design decisions:
 *   • Use a hash map `keyMap` to locate any node by key in O(1).
 *   • Use another hash map `freqMap` that maps a frequency value to a doubly
 *     linked list of all nodes that currently have that frequency.
 *   • Each list is ordered by recency: most recent accesses are at the front,
 *     least recent at the tail. This way, when we need to evict from a given
 *     frequency, we simply remove the tail (least recent in that group).
 *   • `minFreq` keeps track of the smallest frequency that currently has at
 *     least one node. This makes eviction O(1) because we always evict from
 *     `freqMap[minFreq]->removeLast()`.
 *   • Doubly linked lists with dummy head/tail simplify insertion and removal
 *     without null checks.
 * ============================================================================
 */

#include <unordered_map>
using namespace std;

class LFUCache {
private:
    // ---------- Node definition ----------
    struct Node {
        int key;
        int value;
        int freq;          // current access count
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;       // new nodes start with frequency 1
            prev = nullptr;
            next = nullptr;
        }
    };

    // ---------- Doubly linked list with dummy head/tail ----------
    struct List {
        Node* head;
        Node* tail;
        int size;          // number of real nodes in the list

        List() {
            // Dummy nodes simplify edge cases (no need to check for nullptr)
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        // Remove an arbitrary node from the list (O(1) because we have its pointers)
        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        // Remove and return the node just before the dummy tail (least recent)
        Node* removeLast() {
            if (size == 0) return nullptr;
            Node* node = tail->prev;
            remove(node);
            return node;
        }

        // Add a node right after the dummy head (most recent position)
        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }
    };

    // ---------- LFU Cache data members ----------
    int capacity;
    int minFreq;                         // smallest frequency with at least one node
    unordered_map<int, Node*> keyMap;    // key -> node pointer (O(1) access)
    unordered_map<int, List*> freqMap;   // frequency -> list of nodes with that frequency

    // ---------- Helper: increase frequency of a node ----------
    void increaseFreq(Node* node) {
        int oldFreq = node->freq;

        // 1. Remove the node from its current frequency list
        freqMap[oldFreq]->remove(node);

        // 2. If this was the only node at the current minimum frequency,
        //    the new minimum becomes oldFreq + 1 (because we are about to
        //    increment this node’s frequency).
        if (oldFreq == minFreq && freqMap[oldFreq]->size == 0) {
            minFreq++;
        }

        // 3. Increment the node's frequency
        node->freq++;

        // 4. Add the node to the list for its new frequency.
        //    Create the list if it does not exist yet.
        if (!freqMap[node->freq]) {
            freqMap[node->freq] = new List();
        }
        freqMap[node->freq]->addFront(node);   // most recent for this frequency
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;          // no frequencies yet
    }

    // ---------- get(key) ----------
    int get(int key) {
        // If key does not exist, return -1 (standard for cache miss)
        if (keyMap.find(key) == keyMap.end())
            return -1;

        Node* node = keyMap[key];

        // Accessing the node increases its frequency
        increaseFreq(node);

        return node->value;
    }

    // ---------- put(key, value) ----------
    void put(int key, int value) {
        // Edge case: capacity 0 means no storage allowed
        if (capacity == 0)
            return;

        // ----- Case 1: Key already exists -----
        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            node->value = value;          // update the value
            increaseFreq(node);           // its frequency increases
            return;
        }

        // ----- Case 2: Cache is full – evict one item -----
        if (keyMap.size() == capacity) {
            // Evict the least recently used node from the minimum frequency list
            Node* victim = freqMap[minFreq]->removeLast();

            // Remove it from the key map
            keyMap.erase(victim->key);

            // Free the memory (cleanup)
            delete victim;
        }

        // ----- Case 3: Insert a brand new key -----
        Node* node = new Node(key, value);   // freq = 1 by constructor
        keyMap[key] = node;

        // Ensure the list for frequency 1 exists
        if (!freqMap[1])
            freqMap[1] = new List();

        freqMap[1]->addFront(node);          // most recent for freq=1

        // The new node is the only one at frequency 1, so minFreq must be 1
        minFreq = 1;
    }
};

/*
 * ============================================================================
 * EXAMPLE – step‑by‑step walkthrough
 * ============================================================================
 * Suppose capacity = 2.
 * 
 * 1. put(1, 10)
 *    - New node (1,10) with freq=1 inserted into freqMap[1].
 *    - minFreq = 1.
 * 
 * 2. put(2, 20)
 *    - New node (2,20) with freq=1 inserted at front of freqMap[1].
 *      List freqMap[1]: head <-> (2,20) <-> (1,10) <-> tail
 *      (2 is most recent, 1 is least recent among freq=1)
 *    - minFreq stays 1.
 * 
 * 3. get(1)
 *    - Access node (1,10). oldFreq=1.
 *    - Remove it from freqMap[1]; list now has only (2,20).
 *    - oldFreq (1) == minFreq and freqMap[1]->size == 0? Yes, so minFreq becomes 2.
 *    - node.freq becomes 2. Insert into freqMap[2] (front).
 *    - Now freqMap[1] contains (2,20), freqMap[2] contains (1,10).
 *    - minFreq = 2 because freqMap[1] is empty? Wait! After removal, freqMap[1] still
 *      has (2,20)! So size is not 0. So minFreq stays 1. Correct: we only increment
 *      minFreq if the list at oldFreq becomes empty.
 * 
 * 4. put(3, 30)
 *    - Cache is full (size=2). Evict one:
 *      minFreq = 1. freqMap[1] contains (2,20). removeLast() removes tail -> (2,20).
 *    - Remove key 2 from keyMap and delete node.
 *    - Insert new node (3,30) with freq=1 into freqMap[1].
 *    - minFreq = 1.
 * 
 * Final state:
 *   freqMap[1]: (3,30) <-> (1,10)? Wait, (1,10) has freq=2, so no.
 *   Actually after step 3, (1,10) is in freqMap[2]. So freqMap[1] has (3,30) only.
 *   freqMap[2] has (1,10). minFreq = 1.
 * 
 * Next get(1) would move (1,10) to freq=3, and if freqMap[2] becomes empty,
 * minFreq would become 3 (unless other frequencies exist).
 * 
 * ============================================================================
 * WHY THIS DESIGN WORKS (first principles)
 * ============================================================================
 * - We need O(1) for every operation. Hash maps give O(1) lookup.
 * - We need to maintain order within each frequency to know the least recently used.
 *   A doubly linked list gives O(1) insertion at front, O(1) removal from arbitrary
 *   position, and O(1) removal from tail.
 * - The `minFreq` variable avoids scanning all frequencies to find the smallest one
 *   with nodes. It is updated only when the list of the current minimum becomes empty
 *   (and we always increment by one). This maintains O(1) eviction.
 * - Dummy head/tail nodes eliminate edge cases when inserting/removing at boundaries.
 * - We store the frequency inside each Node so we know its current list without
 *   having to look it up.
 * ============================================================================
 */