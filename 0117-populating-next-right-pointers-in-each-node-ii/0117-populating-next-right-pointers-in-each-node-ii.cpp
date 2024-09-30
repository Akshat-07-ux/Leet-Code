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
        if (!root) return nullptr;  // If the root is null, return immediately.
        
        std::queue<Node*> q;
        q.push(root);
        
        // Perform a level order traversal using a queue.
        while (!q.empty()) {
            int size = q.size();
            
            // Traverse nodes at the current level.
            for (int i = 0; i < size; ++i) {
                Node* curr = q.front();
                q.pop();
                
                // Link the current node's next pointer to the next node in the queue (if available).
                if (i < size - 1) {
                    curr->next = q.front();  // Point to the next node in the same level.
                }
                
                // Add the children of the current node to the queue for the next level.
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        
        return root;  // Return the modified tree.
    }
};