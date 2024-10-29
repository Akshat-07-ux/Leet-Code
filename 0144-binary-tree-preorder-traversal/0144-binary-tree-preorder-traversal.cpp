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
    // Recursive solution
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        result.push_back(node->val);      // Visit root
        preorder(node->left, result);     // Visit left subtree
        preorder(node->right, result);    // Visit right subtree
    }

    // Iterative solution
    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            result.push_back(node->val);  // Visit root

            if (node->right != nullptr) stack.push(node->right); // Right child first
            if (node->left != nullptr) stack.push(node->left);   // Left child last
        }

        return result;
    }
};