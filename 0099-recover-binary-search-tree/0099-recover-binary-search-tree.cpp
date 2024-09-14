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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void recoverTree(TreeNode* root) {
        // In-order traversal to identify the two swapped nodes
        inorder(root);

        // Swap the values of the two nodes to correct the tree
        if (first && second) {
            swap(first->val, second->val);
        }
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        // Traverse the left subtree
        inorder(root->left);

        // Detect the swapped nodes
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
            }
            second = root;
        }

        // Update the previous node
        prev = root;

        // Traverse the right subtree
        inorder(root->right);
    }
};