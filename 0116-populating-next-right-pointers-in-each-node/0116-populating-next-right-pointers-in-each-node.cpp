/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        
        // Start with the leftmost node of the current level
        Node* leftmost = root;
        
        // Continue until we reach the leaves
        while (leftmost->left) {
            // Traverse the current level and establish connections for the next level
            Node* head = leftmost;
            while (head) {
                // Connect the left child to the right child
                head->left->next = head->right;
                
                // If there's a next node, connect the current node's right child to the next node's left child
                if (head->next) {
                    head->right->next = head->next->left;
                }
                
                // Move to the next node in the current level
                head = head->next;
            }
            
            // Move down to the next level
            leftmost = leftmost->left;
        }
        
        return root;
    }
};