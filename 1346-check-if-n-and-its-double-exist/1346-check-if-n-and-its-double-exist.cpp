class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Use an unordered_set to keep track of seen elements
        unordered_set<int> seen;

        for (int num : arr) {
            // Check if double or half of the current number exists in the set
            if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            // Add the current number to the set
            seen.insert(num);
        }
        
        return false; // No such pair found
    }
};
