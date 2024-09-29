class AllOne {
    // A doubly linked list node to store counts and corresponding keys
    struct Bucket {
        int count; // The count this bucket represents
        unordered_set<string> keys; // The keys with this count
        Bucket(int cnt) : count(cnt) {}
    };
    
    list<Bucket> buckets; // The linked list storing buckets
    unordered_map<string, list<Bucket>::iterator> keyMap; // Key to bucket iterator
    unordered_map<int, list<Bucket>::iterator> countMap; // Count to bucket iterator

public:
    AllOne() {}

    void inc(string key) {
        if (keyMap.find(key) == keyMap.end()) {
            // Key is new, so insert it with count 1
            if (buckets.empty() || buckets.front().count != 1) {
                buckets.push_front(Bucket(1));
                countMap[1] = buckets.begin();
            }
            buckets.front().keys.insert(key);
            keyMap[key] = buckets.begin();
        } else {
            // Increase the count of the key
            auto currBucket = keyMap[key];
            int newCount = currBucket->count + 1;
            
            // Move the key to the next bucket
            auto nextBucket = next(currBucket);
            if (nextBucket == buckets.end() || nextBucket->count != newCount) {
                // If there is no bucket with the new count, create one
                nextBucket = buckets.insert(nextBucket, Bucket(newCount));
                countMap[newCount] = nextBucket;
            }
            nextBucket->keys.insert(key);
            keyMap[key] = nextBucket;

            // Remove the key from the current bucket
            currBucket->keys.erase(key);
            if (currBucket->keys.empty()) {
                countMap.erase(currBucket->count);
                buckets.erase(currBucket);
            }
        }
    }

    void dec(string key) {
        auto currBucket = keyMap[key];
        int newCount = currBucket->count - 1;
        
        if (newCount == 0) {
            // Remove the key completely if its count becomes zero
            keyMap.erase(key);
        } else {
            // Move the key to the previous bucket
            auto prevBucket = prev(currBucket);
            if (currBucket == buckets.begin() || prevBucket->count != newCount) {
                // If there is no bucket with the new count, create one
                prevBucket = buckets.insert(currBucket, Bucket(newCount));
                countMap[newCount] = prevBucket;
            }
            prevBucket->keys.insert(key);
            keyMap[key] = prevBucket;
        }

        // Remove the key from the current bucket
        currBucket->keys.erase(key);
        if (currBucket->keys.empty()) {
            countMap.erase(currBucket->count);
            buckets.erase(currBucket);
        }
    }

    string getMaxKey() {
        return buckets.empty() ? "" : *buckets.back().keys.begin();
    }

    string getMinKey() {
        return buckets.empty() ? "" : *buckets.front().keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */