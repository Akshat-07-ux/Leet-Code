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
    // Function to find all root-to-leaf paths where the sum equals targetSum
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;  // To store all valid paths
        vector<int> currentPath;     // To store the current path
        dfs(root, targetSum, currentPath, result);  // Perform DFS
        return result;
    }
    
    // Helper function for DFS
    void dfs(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return;  // If the node is null, return
        
        // Add the current node value to the path
        currentPath.push_back(node->val);
        
        // Check if it's a leaf node and if the path sum equals targetSum
        if (!node->left && !node->right && targetSum == node->val) {
            result.push_back(currentPath);  // Add the current path to the result
        }
        
        // Recur for the left and right children with the updated targetSum
        dfs(node->left, targetSum - node->val, currentPath, result);
        dfs(node->right, targetSum - node->val, currentPath, result);
        
        // Backtrack by removing the last added node value
        currentPath.pop_back();
    }
};