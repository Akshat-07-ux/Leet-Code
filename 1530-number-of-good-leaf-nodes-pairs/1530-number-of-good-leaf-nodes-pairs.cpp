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
private:
    int goodPairs = 0;
    
    vector<int> dfs(TreeNode* node, int distance) {
        if (!node) return {};
        
        if (!node->left && !node->right) return {1};
        
        vector<int> left = dfs(node->left, distance);
        vector<int> right = dfs(node->right, distance);
        
        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) goodPairs++;
            }
        }
        
        vector<int> result;
        for (int l : left) {
            if (l < distance) result.push_back(l + 1);
        }
        for (int r : right) {
            if (r < distance) result.push_back(r + 1);
        }
        
        return result;
    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return goodPairs;
    }
};