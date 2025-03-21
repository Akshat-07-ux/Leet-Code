class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree; // To count dependencies for each recipe
        unordered_map<string, vector<string>> graph; // Adjacency list for recipe dependencies
        unordered_set<string> available(supplies.begin(), supplies.end()); // Set of available ingredients
        queue<string> q;
        vector<string> result;

        // Initialize inDegree and graph
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size(); // Count required ingredients
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]); // Ingredient -> dependent recipes
            }
        }

        // Add initially available ingredients to queue
        for (const string& supply : supplies) {
            q.push(supply);
        }

        // Process ingredients and recipes using topological sorting
        while (!q.empty()) {
            string item = q.front();
            q.pop();

            if (inDegree.find(item) != inDegree.end()) { // If it's a recipe
                result.push_back(item);
            }

            // Reduce dependencies for recipes that depend on this ingredient
            for (const string& dependent : graph[item]) {
                if (--inDegree[dependent] == 0) { // If all ingredients are now available
                    q.push(dependent);
                }
            }
        }

        return result;
    }
};