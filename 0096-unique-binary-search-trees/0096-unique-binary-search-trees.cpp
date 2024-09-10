class Solution {
public:
    int numTrees(int n) {
        // dp[i] will store the number of unique BSTs that can be formed with i nodes
        vector<int> dp(n + 1, 0);

        // Base cases
        dp[0] = 1;  // There's one empty tree
        dp[1] = 1;  // One node tree

        // Fill dp array for all nodes from 2 to n
        for (int nodes = 2; nodes <= n; ++nodes) {
            for (int root = 1; root <= nodes; ++root) {
                int leftSubtrees = dp[root - 1];          // Number of BSTs that can be formed from the left side of the root
                int rightSubtrees = dp[nodes - root];     // Number of BSTs that can be formed from the right side of the root
                dp[nodes] += leftSubtrees * rightSubtrees;  // Total for this root is product of left and right subtrees
            }
        }

        // Return the number of unique BSTs that can be formed with n nodes
        return dp[n];
    }
};