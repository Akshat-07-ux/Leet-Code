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
    ListNode* swapPairs(ListNode* head) {
        // If the list is empty or has only one node, no swap needed
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Dummy node to handle the case of swapping the first two nodes
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (prev->next != nullptr && prev->next->next != nullptr) {
            // Nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = first->next;
            
            // Perform the swap
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move to the next pair
            prev = first;
        }
        
        return dummy.next;
    }
};