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
    // Helper function to build the tree
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
                              int preStart, int preEnd, int inStart, int inEnd, 
                              unordered_map<int, int>& inorderMap) {
        // Base case: if there are no elements to construct the tree
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        // The first element in preorder is the root
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find the index of the root in inorder traversal
        int rootIndex = inorderMap[rootVal];
        
        // Calculate the number of elements in the left subtree
        int leftTreeSize = rootIndex - inStart;
        
        // Recursively build the left subtree
        root->left = buildTreeHelper(preorder, inorder, 
                                     preStart + 1, preStart + leftTreeSize, 
                                     inStart, rootIndex - 1, inorderMap);
        
        // Recursively build the right subtree
        root->right = buildTreeHelper(preorder, inorder, 
                                      preStart + leftTreeSize + 1, preEnd, 
                                      rootIndex + 1, inEnd, inorderMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store the indices of inorder elements for fast lookup
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        // Call the helper function to build the tree
        return buildTreeHelper(preorder, inorder, 
                               0, preorder.size() - 1, 
                               0, inorder.size() - 1, 
                               inorderMap);
    }
};