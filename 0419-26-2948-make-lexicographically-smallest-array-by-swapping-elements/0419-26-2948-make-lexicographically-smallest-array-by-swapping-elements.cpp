class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Create pairs of (value, original index)
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < n; i++) {
            indexed_nums.push_back({nums[i], i});
        }
        
        // Sort by value
        sort(indexed_nums.begin(), indexed_nums.end());
        
        // Group indices that can be swapped within limit
        vector<vector<int>> groups;
        vector<int> current_group = {indexed_nums[0].second};
        
        for (int i = 1; i < n; i++) {
            // Check if can be grouped with previous element
            if (indexed_nums[i].first - indexed_nums[i-1].first <= limit) {
                current_group.push_back(indexed_nums[i].second);
            } else {
                // Start new group
                groups.push_back(current_group);
                current_group = {indexed_nums[i].second};
            }
        }
        groups.push_back(current_group);
        
        // Sort indices within each group
        vector<int> result(n);
        int idx = 0;
        for (auto& group : groups) {
            // Sort original indices within each group
            sort(group.begin(), group.end());
            
            // Rearrange sorted values to these sorted indices
            for (int orig_idx : group) {
                result[orig_idx] = indexed_nums[idx].first;
                idx++;
            }
        }
        
        return result;
    }
};