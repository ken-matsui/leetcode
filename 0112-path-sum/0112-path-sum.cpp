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
    bool preorder(TreeNode* node, int targetSum, int sum) {
        if (!node) {
            return false;
        }

        sum += node->val;
        if (!node->left && !node->right) {
            // leaf
            return sum == targetSum;
        }

        if (preorder(node->left, targetSum, sum)) {
            return true;
        }
        if (preorder(node->right, targetSum, sum)) {
            return true;
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        return preorder(root, targetSum, 0);
    }
};