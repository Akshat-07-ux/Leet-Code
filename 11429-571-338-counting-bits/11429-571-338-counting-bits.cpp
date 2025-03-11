class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0); // Initialize an array of size (n+1) with all zeros
        
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i / 2] + (i % 2); // Using previously computed results
        }
        
        return ans;
    }
};