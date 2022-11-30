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
    int depth(TreeNode* root, const int dep) {
        if (root == nullptr) {
            return dep;
        }
        return max(depth(root->left, dep + 1), depth(root->right, dep + 1));
    }

    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }
};
