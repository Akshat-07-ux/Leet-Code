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
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    
private:
    // Helper function to validate the BST property with a range
    bool validate(TreeNode* node, long long low, long long high) {
        // An empty tree is a valid BST
        if (!node) {
            return true;
        }
        
        // The current node's value must be within the range (low, high)
        if (node->val <= low || node->val >= high) {
            return false;
        }
        
        // Recursively check the left subtree and right subtree
        // The left subtree must have values less than the current node's value
        // The right subtree must have values greater than the current node's value
        return validate(node->left, low, node->val) &&
               validate(node->right, node->val, high);
    }
};