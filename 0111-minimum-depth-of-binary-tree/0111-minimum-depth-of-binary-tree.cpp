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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;  // If the tree is empty, return 0

        // Use a queue for BFS
        std::queue<std::pair<TreeNode*, int>> q;  // Pair of node and its depth
        q.push({root, 1});  // Start from the root at depth 1

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;
            int depth = current.second;

            // Check if this node is a leaf node
            if (node->left == nullptr && node->right == nullptr) {
                return depth;  // Return the depth if it is a leaf node
            }

            // Otherwise, add the children to the queue with incremented depth
            if (node->left != nullptr) {
                q.push({node->left, depth + 1});
            }
            if (node->right != nullptr) {
                q.push({node->right, depth + 1});
            }
        }

        return 0;  // This line will never be reached as we will find a leaf
    }
};
