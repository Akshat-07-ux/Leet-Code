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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // Pointer to store the previous node
        ListNode* curr = head;   // Pointer to the current node

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // Store the next node
            curr->next = prev;              // Reverse the current node's pointer
            prev = curr;                    // Move the 'prev' pointer one step forward
            curr = nextNode;                // Move the 'curr' pointer one step forward
        }

        return prev; // 'prev' will be the new head of the reversed list
    }
};
