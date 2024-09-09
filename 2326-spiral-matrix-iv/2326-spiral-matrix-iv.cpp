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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Create an empty m x n matrix initialized with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        ListNode* current = head;
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right across the top row
            for (int i = left; i <= right && current != nullptr; ++i) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            top++;
            
            // Traverse from top to bottom down the right column
            for (int i = top; i <= bottom && current != nullptr; ++i) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            right--;
            
            // Traverse from right to left across the bottom row
            for (int i = right; i >= left && current != nullptr; --i) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            bottom--;
            
            // Traverse from bottom to top up the left column
            for (int i = bottom; i >= top && current != nullptr; --i) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            left++;
        }
        
        return matrix;
    }
};