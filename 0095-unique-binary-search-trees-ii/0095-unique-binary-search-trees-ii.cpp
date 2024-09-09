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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTreesHelper(1, n);
    }

private:
    // Helper function to generate all trees with values in the range [start, end]
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> allTrees;

        // Base case: if start > end, return a vector with nullptr (empty tree)
        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }

        // Iterate through each number between start and end as the root
        for (int i = start; i <= end; ++i) {
            // Generate all possible left subtrees with values less than i
            vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);

            // Generate all possible right subtrees with values greater than i
            vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

            // Combine each left and right subtree with the current root i
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }

        return allTrees;
    }
};