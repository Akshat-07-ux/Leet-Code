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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        
        // Min-heap to store the top k largest level sums
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        // Queue for BFS traversal
        queue<TreeNode*> q;
        q.push(root);
        
        // BFS level-by-level traversal
        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Accumulate the sum for the current level
                levelSum += node->val;
                
                // Add children to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Add the level sum to the min-heap
            minHeap.push(levelSum);
            
            // If the heap size exceeds k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // If there are fewer than k levels, return -1
        if (minHeap.size() < k) return -1;
        
        // The root of the min-heap will be the kth largest element
        return minHeap.top();
    }
};