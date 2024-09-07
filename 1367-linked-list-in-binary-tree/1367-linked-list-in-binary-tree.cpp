/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // Helper function to check if the list starting from 'head' matches the path starting from 'root'
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;  // If the linked list is fully traversed, we found a match
        if (!root) return false; // If the binary tree node is null but the list isn't, return false
        if (head->val != root->val) return false; // Mismatch in values

        // Continue checking downwards in both left and right subtree
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }

    // Main function to check if the linked list is a subpath in the binary tree
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false; // If the tree is empty, return false
        // Start a new path search at the current root, or check its left and right subtrees
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};