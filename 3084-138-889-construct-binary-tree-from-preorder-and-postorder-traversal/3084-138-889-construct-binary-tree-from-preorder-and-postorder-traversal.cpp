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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        
        // Store postorder indices for quick lookup
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }

        int preIndex = 0;
        return buildTree(preorder, postorder, preIndex, 0, postorder.size() - 1, postIndex);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int& preIndex, int postStart, int postEnd, unordered_map<int, int>& postIndex) {
        if (preIndex >= preorder.size() || postStart > postEnd) 
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]); // Create root from preorder

        // Base case: if there is only one element left, return it
        if (postStart == postEnd) return root;

        // The next element in preorder is the left child
        int leftSubtreeRoot = preorder[preIndex];
        int leftIndex = postIndex[leftSubtreeRoot];

        // Recursively construct left and right subtrees
        root->left = buildTree(preorder, postorder, preIndex, postStart, leftIndex, postIndex);
        root->right = buildTree(preorder, postorder, preIndex, leftIndex + 1, postEnd - 1, postIndex);

        return root;
    }
};
