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
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes to start the less and greater/equal lists
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);
        
        // Pointers to the current nodes in the less and greater/equal lists
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;
        
        // Traverse the original list and partition the nodes
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head; // Add to the less list
                less = less->next;
            } else {
                greater->next = head; // Add to the greater/equal list
                greater = greater->next;
            }
            head = head->next;
        }
        
        // Connect the two partitions
        greater->next = nullptr; // End the greater list
        less->next = greaterHead->next; // Combine less and greater lists
        
        // The new head is the start of the less list
        ListNode* newHead = lessHead->next;
        
        // Cleanup the dummy nodes
        delete lessHead;
        delete greaterHead;
        
        return newHead;
    }
};
