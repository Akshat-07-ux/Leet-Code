class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k_(k) {
        // Initialize the min-heap with the first k elements of the array
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k_) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }

private:
    int k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */