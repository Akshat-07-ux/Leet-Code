class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        for (int i = 0; i < n; i++) indices[i] = i;
        
        // Sort robots by position
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        stack<int> s;
        vector<bool> survived(n, true);
        
        for (int i : indices) {
            if (directions[i] == 'R') {
                s.push(i);
            } else {
                while (!s.empty() && survived[i]) {
                    int j = s.top();
                    if (healths[i] < healths[j]) {
                        survived[i] = false;
                        healths[j]--;
                    } else if (healths[i] > healths[j]) {
                        s.pop();
                        survived[j] = false;
                        healths[i]--;
                    } else {
                        s.pop();
                        survived[i] = survived[j] = false;
                    }
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (survived[i]) {
                result.push_back(healths[i]);
            }
        }
        
        return result;
    }
};