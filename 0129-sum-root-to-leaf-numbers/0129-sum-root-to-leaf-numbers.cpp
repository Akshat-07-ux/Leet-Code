/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to perform DFS and calculate the sum
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0; // Base case: null node contributes nothing to the sum
        
        // Update the current sum with the value of the current node
        currentSum = currentSum * 10 + node->val;
        
        // If this is a leaf node, return the current sum
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        // Recurse on left and right subtrees
        int leftSum = dfs(node->left, currentSum);
        int rightSum = dfs(node->right, currentSum);
        
        // Return the total sum from both subtrees
        return leftSum + rightSum;
    }
    
    int sumNumbers(TreeNode* root) {
        // Start the DFS traversal from the root with an initial sum of 0
        return dfs(root, 0);
    }
};