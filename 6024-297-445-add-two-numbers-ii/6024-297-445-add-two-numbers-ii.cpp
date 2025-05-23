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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        // Push all elements from l1 to s1
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push all elements from l2 to s2
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = nullptr;
        int carry = 0;

        // Pop from stacks and add digits
        while (!s1.empty() || !s2.empty() || carry > 0) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;
            int digit = sum % 10;

            // Create new node and insert at head
            ListNode* newNode = new ListNode(digit);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};