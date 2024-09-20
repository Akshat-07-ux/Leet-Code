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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;  // If root is null, return an empty vector
        
        queue<TreeNode*> q;
        q.push(root);
        
        // Perform level-order traversal
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> current_level;
            
            // Process each node at the current level
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                current_level.push_back(node->val);
                
                // Add the left and right children to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Add the current level's values to the result
            result.push_back(current_level);
        }
        
        // Reverse the result to get bottom-up order
        reverse(result.begin(), result.end());
        return result;
    }
};