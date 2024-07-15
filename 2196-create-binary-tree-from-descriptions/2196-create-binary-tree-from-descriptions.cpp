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
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> childSet;

        // Create nodes and establish parent-child relationships
        for (const auto& desc : descriptions) {
            int parent = desc[0], child = desc[1], isLeft = desc[2];
            
            if (nodeMap.find(parent) == nodeMap.end()) {
                nodeMap[parent] = new TreeNode(parent);
            }
            if (nodeMap.find(child) == nodeMap.end()) {
                nodeMap[child] = new TreeNode(child);
            }
            
            if (isLeft) {
                nodeMap[parent]->left = nodeMap[child];
            } else {
                nodeMap[parent]->right = nodeMap[child];
            }
            
            childSet.insert(child);
        }

        // Find the root (node that is not a child of any other node)
        TreeNode* root = nullptr;
        for (const auto& pair : nodeMap) {
            if (childSet.find(pair.first) == childSet.end()) {
                root = pair.second;
                break;
            }
        }

        return root;
    }
};