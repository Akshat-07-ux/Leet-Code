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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; // To store the final zigzag level order traversal
        if (!root) return result;   // If root is null, return empty result
        
        queue<TreeNode*> q;         // Queue for BFS traversal
        q.push(root);
        bool leftToRight = true;    // Flag to determine the order of traversal
        
        while (!q.empty()) {
            int levelSize = q.size();
            deque<int> level;       // Use deque to insert elements from both ends based on direction
            
            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Insert node's value based on the current traversal direction
                if (leftToRight) {
                    level.push_back(node->val);  // Left to right, append to the end
                } else {
                    level.push_front(node->val); // Right to left, insert at the front
                }
                
                // Add children to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(vector<int>(level.begin(), level.end())); // Add current level to result
            leftToRight = !leftToRight;  // Toggle the direction for the next level
        }
        
        return result;
    }
};