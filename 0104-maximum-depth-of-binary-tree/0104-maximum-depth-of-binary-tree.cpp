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
    int depth(TreeNode* root, int d) {
        if (!root) {
            return d;
        }
        return max(depth(root->left, d + 1), depth(root->right, d + 1));
    }

public:
    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }
};
