class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        // If endWord is not in the word list, return empty result
        if (wordSet.find(endWord) == wordSet.end()) return result;

        // To store the shortest paths graph and distance of each word from the beginWord
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> dist;

        // Initialize BFS
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;
        
        // BFS to build the graph of the shortest paths
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int currDist = dist[word];
            
            // Generate all possible one-letter transformations
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (wordSet.find(temp) != wordSet.end()) {
                        // If we encounter this word for the first time, set its distance
                        if (dist.find(temp) == dist.end()) {
                            dist[temp] = currDist + 1;
                            q.push(temp);
                        }
                        
                        // Add to the graph if it's on the shortest path
                        if (dist[temp] == currDist + 1) {
                            graph[temp].push_back(word);
                        }
                    }
                }
            }
        }

        // If the endWord is not reachable, return an empty result
        if (dist.find(endWord) == dist.end()) return result;

        // Backtracking to generate all the shortest transformation sequences
        vector<string> path = {endWord};
        backtrack(result, graph, path, beginWord, endWord);

        return result;
    }

private:
    // Backtracking function to generate paths
    void backtrack(vector<vector<string>>& result, unordered_map<string, vector<string>>& graph, 
                   vector<string>& path, string& beginWord, string word) {
        if (word == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            result.push_back(validPath);
            return;
        }
        
        for (string prev : graph[word]) {
            path.push_back(prev);
            backtrack(result, graph, path, beginWord, prev);
            path.pop_back();
        }
    }
};