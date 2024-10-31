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
    ListNode* insertionSortList(ListNode* head) {
        // If list is empty or has only one node, return as is
        if (!head || !head->next) return head;
        
        // Dummy node to simplify insertion at the beginning
        ListNode* dummy = new ListNode(0);
        
        // Current node to be inserted
        ListNode* current = head;
        
        while (current) {
            // Store the next node before we modify current's next
            ListNode* next = current->next;
            
            // Find the right position to insert current node
            ListNode* insertPos = dummy;
            
            // Traverse the sorted portion to find insertion point
            while (insertPos->next && insertPos->next->val < current->val) {
                insertPos = insertPos->next;
            }
            
            // Insert current node
            current->next = insertPos->next;
            insertPos->next = current;
            
            // Move to next node in original list
            current = next;
        }
        
        // Return sorted list (skip dummy node)
        return dummy->next;
    }
};