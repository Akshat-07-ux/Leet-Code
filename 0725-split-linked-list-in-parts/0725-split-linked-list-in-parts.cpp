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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Count the total number of nodes
        int totalLength = 0;
        ListNode* current = head;
        while (current != nullptr) {
            totalLength++;
            current = current->next;
        }
        
        // Step 2: Calculate base size and remainder
        int baseSize = totalLength / k;  // Base size for each part
        int extraNodes = totalLength % k; // Number of parts that need an extra node
        
        vector<ListNode*> result(k, nullptr);  // Result array of k parts
        current = head;
        
        // Step 3: Split the list
        for (int i = 0; i < k && current != nullptr; i++) {
            result[i] = current;  // Start of the i-th part
            int partSize = baseSize + (i < extraNodes ? 1 : 0);  // Size of current part
            
            // Traverse to the end of the current part
            for (int j = 1; j < partSize; j++) {
                current = current->next;
            }
            
            // Break the link to the next part
            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }
        
        return result;
    }
};