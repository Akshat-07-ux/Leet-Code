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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Base cases:
        if (!root1 && !root2) return true;  // Both trees are null
        if (!root1 || !root2) return false; // One of the trees is null
        if (root1->val != root2->val) return false; // Values do not match

        // Recursively check if the trees are flip equivalent:
        // There are two possible cases:
        // 1. Either both subtrees are already flip equivalent without flipping
        // 2. Or, after flipping the left and right children of one tree, they become flip equivalent.
        
        bool withoutFlip = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        bool withFlip = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

        // Return true if either of the two conditions hold.
        return withoutFlip || withFlip;
    }
};