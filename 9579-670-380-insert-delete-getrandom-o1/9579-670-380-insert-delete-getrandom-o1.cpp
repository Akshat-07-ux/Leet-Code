class RandomizedSet {
private:
    std::unordered_map<int, int> valToIndex; // val -> index in vector
    std::vector<int> values; // stores the actual values

public:
    RandomizedSet() {
        // Constructor, nothing to initialize explicitly
    }
    
    bool insert(int val) {
        if (valToIndex.count(val)) return false; // already present
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!valToIndex.count(val)) return false; // not present
        int index = valToIndex[val];
        int lastElement = values.back();

        // Swap the element with the last one
        values[index] = lastElement;
        valToIndex[lastElement] = index;

        // Remove the last element
        values.pop_back();
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }
};