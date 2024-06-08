#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Create an unordered map to store value and its index
        std::unordered_map<int, int> hash_map;

        // Iterate over the vector with index and value
        for (int index = 0; index < nums.size(); ++index) {
            int value = nums[index];
            // Calculate the complement
            int complement = target - value;

            // Check if the complement exists in the hash map
            if (hash_map.find(complement) != hash_map.end()) {
                // If found, return the indices
                return {hash_map[complement], index};
            }

            // Add the current number and its index to the hash map
            hash_map[value] = index;
        }

        // Return an empty vector if no solution is found (shouldn't happen as per problem statement)
        return {};
    }
};
