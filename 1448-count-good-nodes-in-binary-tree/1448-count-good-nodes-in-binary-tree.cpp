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
    void countGood(TreeNode* node, int& count, int maxVal) {
        if (!node) {
            return;
        }
        if (node->val >= maxVal) {
            ++count;
            maxVal = node->val;
        }
        countGood(node->left, count, maxVal);
        countGood(node->right, count, maxVal);
    }

public:
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int count = 0;
        countGood(root, count, INT_MIN);
        return count;
    }
};
