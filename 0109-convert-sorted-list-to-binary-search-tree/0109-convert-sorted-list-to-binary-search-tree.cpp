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
    // Function to find the middle of the linked list.
    ListNode* findMiddle(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr; // To track the node before the middle
        
        // Use the two-pointer technique to find the middle of the list
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If there was a previous node, disconnect the left half from the middle
        if (prev != nullptr) {
            prev->next = nullptr;
        }
        
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        // Base cases
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        
        // Find the middle node of the list
        ListNode* mid = findMiddle(head);
        
        // The middle element becomes the root
        TreeNode* root = new TreeNode(mid->val);
        
        // Recursively convert the left half of the list into the left subtree
        root->left = sortedListToBST(head);
        
        // Recursively convert the right half of the list into the right subtree
        root->right = sortedListToBST(mid->next);
        
        return root;
    }
};
