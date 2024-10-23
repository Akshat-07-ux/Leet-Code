/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Clone the nodes and interweave them with the original list
        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            copy->next = current->next; // Point to the next node
            current->next = copy;        // Insert the copy right after the current node
            current = copy->next;        // Move to the next original node
        }

        // Step 2: Assign random pointers for the copied nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next; // Link to the random node's copy
            }
            current = current->next->next; // Move to the next original node
        }

        // Step 3: Separate the copied list from the original list
        current = head;
        Node* copiedHead = head->next; // The head of the copied list
        while (current) {
            Node* copy = current->next; // Get the copied node
            current->next = copy->next;  // Restore the original list
            if (copy->next) {
                copy->next = copy->next->next; // Point to the next copied node
            }
            current = current->next; // Move to the next original node
        }

        return copiedHead; // Return the head of the copied list
    }
};