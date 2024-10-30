class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // Doubly linked list to store keys and values in usage order
    unordered_map<int, list<pair<int, int>>::iterator> map; // Hash map for O(1) access to list nodes

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1; // Key not found
        }

        // Move the accessed node to the front of the list
        auto it = map[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        map[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        // If key exists, update value and move to front
        if (map.find(key) != map.end()) {
            auto it = map[key];
            cache.erase(it);
        } else if (cache.size() == capacity) {
            // Cache is full; remove the least recently used element (back of the list)
            auto lru = cache.back();
            map.erase(lru.first);
            cache.pop_back();
        }

        // Insert the new key-value pair at the front
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */