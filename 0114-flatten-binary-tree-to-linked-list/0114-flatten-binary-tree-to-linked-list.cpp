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
    void flatten(TreeNode* root) {
        if (!root) return;

        // Flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Store the original right subtree
        TreeNode* tempRight = root->right;
        
        // Move the left subtree to the right
        root->right = root->left;
        root->left = nullptr;  // Set left to nullptr as per the problem statement

        // Traverse to the end of the new right subtree (which was the left subtree)
        TreeNode* curr = root;
        while (curr->right) {
            curr = curr->right;
        }

        // Attach the originally right subtree to the end of the new right subtree
        curr->right = tempRight;
    }
};