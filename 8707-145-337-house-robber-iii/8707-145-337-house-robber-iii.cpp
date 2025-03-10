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
    pair<int, int> robHelper(TreeNode* root) {
        if (!root) return {0, 0};

        // Get max money from left and right subtrees
        pair<int, int> left = robHelper(root->left);
        pair<int, int> right = robHelper(root->right);

        // If we rob this node, we add its value and the money from grandchildren
        int rob_with_root = root->val + left.second + right.second;

        // If we skip this node, we take the max from its children
        int rob_without_root = max(left.first, left.second) + max(right.first, right.second);

        return {rob_with_root, rob_without_root};
    }

    int rob(TreeNode* root) {
        pair<int, int> result = robHelper(root);
        return max(result.first, result.second);
    }
};