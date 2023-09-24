/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    TreeNode* flattenTree(TreeNode* node) {
        if (!node) {
            return nullptr;
        }

        TreeNode* leftFlattened = flattenTree(node->left);
        TreeNode* rightFlattened = flattenTree(node->right);

        node->left = nullptr;

        if (!leftFlattened) {
            return rightFlattened ? node : node;
        }

        TreeNode* temp = leftFlattened;
        while (temp->right) {
            temp = temp->right;
        }
        temp->right = rightFlattened;

        node->right = leftFlattened;
        return node;
    }

public:
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};
