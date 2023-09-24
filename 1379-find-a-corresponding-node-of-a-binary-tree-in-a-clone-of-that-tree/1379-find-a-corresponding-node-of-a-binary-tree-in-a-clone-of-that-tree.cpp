/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {
        if (!original) {
            return nullptr;
        }
        if (original == target) {
            return cloned;
        }
        TreeNode* ref = getTargetCopy(original->left, cloned->left, target);
        if (ref) {
            return ref;
        }
        ref = getTargetCopy(original->right, cloned->right, target);
        if (ref) {
            return ref;
        }
        return nullptr;
    }
};
