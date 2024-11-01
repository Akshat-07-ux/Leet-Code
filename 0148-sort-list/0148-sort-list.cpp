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
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one element
        if (!head || !head->next) {
            return head;
        }
        
        // Step 1: Find the middle of the linked list
        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Split the list into two halves
        
        // Step 2: Recursively sort the two halves
        left = sortList(left);
        right = sortList(right);
        
        // Step 3: Merge the sorted halves
        return merge(left, right);
    }

private:
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move fast two steps and slow one step
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow; // slow is now the middle node
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        // Create a dummy node to simplify the merging process
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Merge the two lists
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        
        // Append the remaining nodes
        tail->next = left ? left : right;
        
        return dummy.next; // Return the merged list
    }
};