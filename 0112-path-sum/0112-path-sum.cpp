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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: If the current node is null, there's no path
        if (root == nullptr) {
            return false;
        }
        
        // If we have reached a leaf node, check if the path sum equals targetSum
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
        // Recursively check the left and right subtrees
        // Subtract the current node's value from targetSum
        int remainingSum = targetSum - root->val;
        
        // If any of the subtree calls return true, return true
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
