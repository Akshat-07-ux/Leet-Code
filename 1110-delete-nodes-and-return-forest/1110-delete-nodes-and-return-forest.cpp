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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        
        function<TreeNode*(TreeNode*, bool)> dfs = [&](TreeNode* node, bool is_root) -> TreeNode* {
            if (!node) return nullptr;
            
            bool delete_current = to_delete_set.count(node->val);
            
            if (is_root && !delete_current) {
                forest.push_back(node);
            }
            
            node->left = dfs(node->left, delete_current);
            node->right = dfs(node->right, delete_current);
            
            return delete_current ? nullptr : node;
        };
        
        dfs(root, true);
        return forest;
    }
};