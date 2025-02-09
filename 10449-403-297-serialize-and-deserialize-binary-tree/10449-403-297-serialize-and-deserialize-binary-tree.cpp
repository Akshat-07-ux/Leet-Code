/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string using level-order traversal
    string serialize(TreeNode* root) {
        if (!root) return "";  // Edge case: empty tree

        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ss << node->val << ",";  // Store the node value
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null,";
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree using level-order traversal
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;  // Edge case: empty string

        stringstream ss(data);
        string val;
        getline(ss, val, ',');  // Read root value

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Read left child
            if (getline(ss, val, ',') && val != "null") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            // Read right child
            if (getline(ss, val, ',') && val != "null") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));