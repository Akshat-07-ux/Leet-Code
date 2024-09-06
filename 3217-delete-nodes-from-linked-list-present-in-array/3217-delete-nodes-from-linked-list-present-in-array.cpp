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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Step 1: Insert all elements of nums into an unordered_set for O(1) lookup.
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Step 2: Create a dummy node to handle edge cases.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        
        // Step 3: Iterate through the list and remove nodes with values in the set.
        while (current->next) {
            if (numSet.count(current->next->val)) {
                // If the value is in numSet, remove the node.
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free the memory of the removed node.
            } else {
                // Otherwise, move to the next node.
                current = current->next;
            }
        }
        
        // Step 4: Return the modified list (without the dummy node).
        ListNode* result = dummy->next;
        delete dummy; // Delete the dummy node to free memory.
        return result;
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
