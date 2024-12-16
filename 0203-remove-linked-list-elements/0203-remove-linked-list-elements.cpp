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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to the head of the list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize current node as the dummy node
        ListNode* current = dummy;
        
        // Iterate through the list
        while (current->next != nullptr) {
            // If the next node's value is equal to val, remove it
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                // Otherwise, move to the next node
                current = current->next;
            }
        }
        
        // Return the head of the modified list (dummy->next points to the new head)
        return dummy->next;
    }
};
