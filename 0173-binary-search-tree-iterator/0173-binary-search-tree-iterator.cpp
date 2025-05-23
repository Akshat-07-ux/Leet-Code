/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> nodeStack;

    // Helper function to push all the left children of a node onto the stack
    void pushLeftNodes(TreeNode* node) {
        while (node) {
            nodeStack.push(node);
            node = node->left;
        }
    }

public:
    // Constructor: Initialize the iterator with the root of the BST
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
    }

    // Returns the next smallest number in the BST
    int next() {
        TreeNode* topNode = nodeStack.top();
        nodeStack.pop();
        if (topNode->right) {
            pushLeftNodes(topNode->right);
        }
        return topNode->val;
    }

    // Returns true if there is a next smallest number
    bool hasNext() {
        return !nodeStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */