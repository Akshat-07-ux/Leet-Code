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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head; // If the list is empty, return head

        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Skip the next node as it is a duplicate
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free the memory of the duplicate node
            } else {
                // Move to the next node if there is no duplicate
                current = current->next;
            }
        }

        return head; // Return the modified list with duplicates removed
    }
};