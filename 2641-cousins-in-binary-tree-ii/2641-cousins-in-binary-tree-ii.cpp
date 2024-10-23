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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) return root;

        // BFS using queue
        std::queue<TreeNode*> q;
        q.push(root);

        // We initialize the root's value to 0 because it has no cousins
        root->val = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;

            // Vector to store the current level nodes
            std::vector<TreeNode*> currentLevelNodes;

            // First pass: Calculate the sum of all node values at this level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                
                // Push nodes to current level vector for later processing
                currentLevelNodes.push_back(node);
                
                // Enqueue the children for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Second pass: Update each node's value with the sum of cousins' values
            for (TreeNode* node : currentLevelNodes) {
                int siblingSum = 0;
                
                // Calculate sibling sum (sum of left and right child if they exist)
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                // Update the children's values with cousin sum
                if (node->left) node->left->val = levelSum - siblingSum;
                if (node->right) node->right->val = levelSum - siblingSum;
            }
        }

        return root;
    }
};