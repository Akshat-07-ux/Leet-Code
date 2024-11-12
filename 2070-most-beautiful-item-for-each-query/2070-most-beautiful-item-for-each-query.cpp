class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Step 1: Sort items by price
        sort(items.begin(), items.end());
        
        // Step 2: Preprocess items to store maximum beauty up to each price
        vector<pair<int, int>> beautyList;
        int maxBeauty = 0;
        for (auto& item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            beautyList.push_back({item[0], maxBeauty});
        }
        
        // Step 3: Prepare to answer queries
        vector<int> result(queries.size());
        vector<pair<int, int>> queriesWithIndex;
        for (int i = 0; i < queries.size(); ++i) {
            queriesWithIndex.push_back({queries[i], i});
        }
        sort(queriesWithIndex.begin(), queriesWithIndex.end());
        
        // Step 4: Use binary search to answer each query
        for (auto& [query, index] : queriesWithIndex) {
            // Use upper_bound to find the highest beauty for the given query price
            auto it = upper_bound(beautyList.begin(), beautyList.end(), make_pair(query, INT_MAX));
            if (it == beautyList.begin()) {
                result[index] = 0; // No item has price <= query
            } else {
                --it; // Move back to the last valid price
                result[index] = it->second;
            }
        }
        
        return result;
    }
};