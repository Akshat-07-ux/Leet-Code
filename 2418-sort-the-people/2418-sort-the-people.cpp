class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> people;
        
        // Create pairs of (height, name)
        for (int i = 0; i < n; i++) {
            people.push_back({heights[i], names[i]});
        }
        
        // Sort the pairs in descending order based on height
        sort(people.rbegin(), people.rend());
        
        // Extract the sorted names
        vector<string> result;
        for (const auto& person : people) {
            result.push_back(person.second);
        }
        
        return result;
    }
};