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
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        // Perform level-order traversal to group node values by levels
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levels.push_back(level);
        }

        // Helper function to calculate minimum swaps needed to sort an array
        auto minSwapsToSort = [](vector<int>& arr) -> int {
            int n = arr.size();
            vector<pair<int, int>> valueIndex;

            for (int i = 0; i < n; ++i) {
                valueIndex.emplace_back(arr[i], i);
            }

            sort(valueIndex.begin(), valueIndex.end());

            vector<bool> visited(n, false);
            int swaps = 0;

            for (int i = 0; i < n; ++i) {
                if (visited[i] || valueIndex[i].second == i) continue;

                int cycleSize = 0;
                int j = i;

                while (!visited[j]) {
                    visited[j] = true;
                    j = valueIndex[j].second;
                    ++cycleSize;
                }

                if (cycleSize > 1) swaps += (cycleSize - 1);
            }

            return swaps;
        };

        // Calculate the total minimum operations needed
        int totalOperations = 0;

        for (auto& level : levels) {
            totalOperations += minSwapsToSort(level);
        }

        return totalOperations;
    }
};
