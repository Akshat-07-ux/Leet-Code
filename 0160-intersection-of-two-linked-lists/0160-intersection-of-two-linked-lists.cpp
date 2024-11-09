/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        // Traverse both lists
        while (ptrA != ptrB) {
            // Move to the next node or switch to the head of the other list
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }

        // Either both pointers meet at the intersection or both are nullptr (no intersection)
        return ptrA;
    }
};