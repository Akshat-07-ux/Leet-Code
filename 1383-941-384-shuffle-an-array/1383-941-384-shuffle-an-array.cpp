class Solution {
private:
    vector<int> original;
    vector<int> current;
    mt19937 rng; // Mersenne Twister RNG

public:
    Solution(vector<int>& nums) {
        original = nums;
        current = nums;
        rng.seed(random_device{}()); // Seed with a truly random value
    }
    
    vector<int> reset() {
        current = original; // Reset to original
        return current;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = current;
        int n = shuffled.size();
        for (int i = 0; i < n; ++i) {
            // generate a random index from i to n-1
            uniform_int_distribution<int> dist(i, n - 1);
            int j = dist(rng);
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */