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
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;  // Initialize global maximum to a very small value
        maxGain(root, globalMax);  // Perform the recursive traversal
        return globalMax;
    }
    
private:
    // Helper function to compute the maximum gain from each subtree
    int maxGain(TreeNode* node, int& globalMax) {
        if (!node) return 0;  // Base case: if the node is null, return 0
        
        // Recursively calculate the maximum contribution from the left and right subtrees
        int leftGain = std::max(maxGain(node->left, globalMax), 0);   // If left contribution is negative, ignore it
        int rightGain = std::max(maxGain(node->right, globalMax), 0); // If right contribution is negative, ignore it
        
        // Path sum including the current node and both children
        int currentPathSum = node->val + leftGain + rightGain;
        
        // Update the global maximum path sum
        globalMax = std::max(globalMax, currentPathSum);
        
        // Return the maximum contribution this node can provide if we use it as part of the path
        return node->val + std::max(leftGain, rightGain);
    }
};