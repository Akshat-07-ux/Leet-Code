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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;  // Base case: empty node
        
        // Step 1: Recurse on the left subtree
        inorderHelper(node->left, result);
        
        // Step 2: Visit the current node
        result.push_back(node->val);
        
        // Step 3: Recurse on the right subtree
        inorderHelper(node->right, result);
    }
};