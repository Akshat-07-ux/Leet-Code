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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: if left == right, no need to reverse, return head.
        if (left == right) {
            return head;
        }

        // Create a dummy node to simplify edge cases where head needs to be reversed.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Traverse to the node just before the `left`-th node.
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // `prev` is now the node just before the `left`-th node.
        ListNode* current = prev->next;  // This is the `left`-th node.
        ListNode* nextNode = nullptr;

        // Step 2: Reverse the sublist from `left` to `right`.
        ListNode* prevSublist = nullptr;
        for (int i = left; i <= right; i++) {
            nextNode = current->next;
            current->next = prevSublist;
            prevSublist = current;
            current = nextNode;
        }

        // Step 3: Reattach the reversed sublist back to the main list.
        prev->next->next = current;  // The `left`-th node is now the tail of the reversed sublist.
        prev->next = prevSublist;    // Connect `prev` to the new head of the reversed sublist.

        // Return the modified list (which might start with the original head or the dummy).
        return dummy->next;
    }
};

// Utility function to print the linked list.
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}