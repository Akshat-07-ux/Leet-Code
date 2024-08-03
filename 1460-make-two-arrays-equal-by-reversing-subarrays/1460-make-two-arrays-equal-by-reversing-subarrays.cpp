class Solution {
public:
    bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
        // Sort both arrays
        std::sort(target.begin(), target.end());
        std::sort(arr.begin(), arr.end());
        
        // Compare the sorted arrays
        return target == arr;
    }
};