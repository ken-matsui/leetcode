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
    int sum(TreeNode* root, const int index, const int deepest) {
        if (!root) {
            return 0;
        }

        if (index == deepest) {
            return root->val;
        }
        return sum(root->left, index + 1, deepest) + sum(root->right, index + 1, deepest);
    }

    int findDeepestIndex(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(findDeepestIndex(root->left), findDeepestIndex(root->right));
    }

    int deepestLeavesSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        const int index = findDeepestIndex(root);
        return sum(root, 1, index);
    }
};
