#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    // Stores the actual pairs: {key, value}
    std::list<std::pair<int, int>> lru_list; 
    // Maps the key to its exact position (iterator) inside the list
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache; 

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        // Move the accessed element to the front of the list in O(1)
        lru_list.splice(lru_list.begin(), lru_list, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists: Update value and move to front
            cache[key]->second = value;
            lru_list.splice(lru_list.begin(), lru_list, cache[key]);
            return;
        }
        
        if (cache.size() == capacity) {
            // Evict Least Recently Used (back of the list)
            int d_key = lru_list.back().first;
            cache.erase(d_key);
            lru_list.pop_back();
        }
        
        // Insert new element at the front
        lru_list.emplace_front(key, value);
        cache[key] = lru_list.begin();
    }
};
