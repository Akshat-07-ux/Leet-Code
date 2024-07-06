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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;

        int firstCritical = -1;
        int lastCritical = -1;
        int prevCritical = -1;
        int minDist = INT_MAX;
        int index = 1;

        while (next) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (firstCritical == -1) {
                    firstCritical = index;
                }
                lastCritical = index;

                if (prevCritical != -1) {
                    minDist = min(minDist, index - prevCritical);
                }
                prevCritical = index;
            }

            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }

        if (firstCritical == lastCritical) {
            return {-1, -1};
        }

        int maxDist = lastCritical - firstCritical;
        return {minDist, maxDist};
    }
};