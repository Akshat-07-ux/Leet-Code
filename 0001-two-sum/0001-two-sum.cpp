#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
       
        std::unordered_map<int, int> hash_map;

        
        for (int index = 0; index < nums.size(); ++index) {
            int value = nums[index];
            
            int complement = target - value;

           
            if (hash_map.find(complement) != hash_map.end()) {
                
                return {hash_map[complement], index};
            }

           
            hash_map[value] = index;
        }

        
        return {};
    }
};
