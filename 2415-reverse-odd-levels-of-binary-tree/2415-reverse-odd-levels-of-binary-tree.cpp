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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;

        // Helper function to perform level order traversal and reverse odd levels
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            std::vector<TreeNode*> currentLevel;

            // Traverse the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node);

                // Add child nodes to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse node values if the level is odd
            if (level % 2 == 1) {
                int left = 0, right = currentLevel.size() - 1;
                while (left < right) {
                    std::swap(currentLevel[left]->val, currentLevel[right]->val);
                    ++left;
                    --right;
                }
            }

            ++level;
        }

        return root;
    }
};