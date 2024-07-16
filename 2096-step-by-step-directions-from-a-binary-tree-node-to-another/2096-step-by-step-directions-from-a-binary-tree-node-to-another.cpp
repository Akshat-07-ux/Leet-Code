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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> path_start, path_dest;
        
        // Find paths from root to start and destination nodes
        findPath(root, startValue, path_start);
        findPath(root, destValue, path_dest);
        
        // Remove common prefix
        while (!path_start.empty() && !path_dest.empty() && 
               path_start.back() == path_dest.back()) {
            path_start.pop_back();
            path_dest.pop_back();
        }
        
        // Build the result string
        string result(path_start.size(), 'U');
        for (int i = path_dest.size() - 1; i >= 0; i--) {
            result += path_dest[i];
        }
        
        return result;
    }

private:
    bool findPath(TreeNode* node, int value, vector<char>& path) {
        if (node == nullptr) {
            return false;
        }
        
        if (node->val == value) {
            return true;
        }
        
        if (findPath(node->left, value, path)) {
            path.push_back('L');
            return true;
        }
        
        if (findPath(node->right, value, path)) {
            path.push_back('R');
            return true;
        }
        
        return false;
    }
};