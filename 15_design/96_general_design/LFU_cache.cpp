#include <unordered_map>
#include <list>
using namespace std;

#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    struct Node {
        int value;                  // Value stored for this key
        int freq;                   // Current access frequency
        list<int>::iterator pos;    // Position of this key in its frequency list
    };

    int capacity;
    int minFreq;

    // key -> {value, frequency, iterator into freqList}
    unordered_map<int, Node> cache;

    // frequency -> keys with that frequency (MRU at front, LRU at back)
    unordered_map<int, list<int>> freqList;

    // Increase the frequency of a key after it is accessed.
    void touch(int key) {
        Node &node = cache[key];
        int freq = node.freq;

        // Remove key from its current frequency list.
        freqList[freq].erase(node.pos);

        // If this was the last key with this frequency,
        // remove the empty list.
        if (freqList[freq].empty()) {
            freqList.erase(freq);

            // If this was the minimum frequency,
            // the minimum frequency increases.
            if (minFreq == freq)
                minFreq++;
        }

        // Move key to the next frequency.
        node.freq++;

        // Insert at the front (most recently used within this frequency).
        freqList[node.freq].push_front(key);

        // Save its new iterator.
        node.pos = freqList[node.freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {

        if (!cache.count(key))
            return -1;

        touch(key);

        return cache[key].value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        // Key already exists.
        if (cache.count(key)) {
            cache[key].value = value;
            touch(key);
            return;
        }

        // Cache full -> evict LFU.
        if (cache.size() == capacity) {

            // LRU key among the minimum frequency.
            int evictKey = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            cache.erase(evictKey);
        }

        // New keys always start at frequency 1.
        freqList[1].push_front(key);

        cache[key] = {
            value,
            1,
            freqList[1].begin()
        };

        minFreq = 1;
    }
};