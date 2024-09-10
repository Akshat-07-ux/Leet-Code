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
    // Function to insert GCD nodes between adjacent nodes
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If the list has only one node, return the head as it is
        if (!head || !head->next) return head;

        ListNode* current = head;

        // Traverse the list
        while (current && current->next) {
            int gcdValue = std::gcd(current->val, current->next->val);  // Find GCD

            // Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(gcdValue);

            // Insert the GCD node between the current and the next node
            gcdNode->next = current->next;
            current->next = gcdNode;

            // Move the pointer two steps forward (to the next original node)
            current = gcdNode->next;
        }

        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
