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
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
    
private:
    int checkBalance(TreeNode* node) {
        if (node == nullptr) {
            return 0; // Height of an empty tree is 0
        }
        
        // Recursively check the height of left and right subtrees
        int leftHeight = checkBalance(node->left);
        int rightHeight = checkBalance(node->right);
        
        // If the left subtree is unbalanced, propagate the -1 up
        if (leftHeight == -1) return -1;
        // If the right subtree is unbalanced, propagate the -1 up
        if (rightHeight == -1) return -1;
        
        // If the current node is balanced, return its height
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Current node is unbalanced
        }
        
        return max(leftHeight, rightHeight) + 1; // Return height
    }
};