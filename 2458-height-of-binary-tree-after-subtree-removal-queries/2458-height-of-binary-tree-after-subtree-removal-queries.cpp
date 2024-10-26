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
    // Structure to store height and depth of each node
    unordered_map<int, int> height, depth;

    // DFS function to compute height and depth of each node
    int dfs(TreeNode* node, int d) {
        if (!node) return -1;  // Base case for null nodes
        
        depth[node->val] = d;  // Set depth of current node
        int leftHeight = dfs(node->left, d + 1);  // Recur for left child
        int rightHeight = dfs(node->right, d + 1);  // Recur for right child
        height[node->val] = max(leftHeight, rightHeight) + 1;  // Height of the current node
        
        return height[node->val];
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);  // Initialize depth and height maps
        
        // Track maximum heights for each depth
        unordered_map<int, vector<int>> maxHeightsAtDepth;
        for (const auto& [node, h] : height) {
            int d = depth[node];
            maxHeightsAtDepth[d].push_back(h);
        }
        
        // For each depth, keep only the top two heights (sorted in descending order)
        unordered_map<int, pair<int, int>> topTwoAtDepth;
        for (auto& [d, heights] : maxHeightsAtDepth) {
            sort(heights.rbegin(), heights.rend());  // Sort in descending order
            topTwoAtDepth[d] = {heights[0], heights.size() > 1 ? heights[1] : -1};
        }
        
        vector<int> answer;
        
        // Answer each query independently
        for (int node : queries) {
            int d = depth[node];
            int currentHeight = height[node];
            
            // If node's height is the highest at this depth, use the second highest
            int newHeight = topTwoAtDepth[d].first == currentHeight ? topTwoAtDepth[d].second : topTwoAtDepth[d].first;
            
            // The new height of the tree if we "removed" this subtree
            answer.push_back(d + newHeight);
        }
        
        return answer;
    }
};