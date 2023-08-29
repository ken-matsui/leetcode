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
    bool isLessThan(TreeNode* root, int val) {
        if (!root) {
            return true;
        }
        
        return root->val < val && isLessThan(root->left, val) && isLessThan(root->right, val);
    }
    bool isGreaterThan(TreeNode* root, int val) {
        if (!root) {
            return true;
        }

        return root->val > val && isGreaterThan(root->left, val) && isGreaterThan(root->right, val);
    }

public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        return isLessThan(root->left, root->val) && isGreaterThan(root->right, root->val) && isValidBST(root->left) && isValidBST(root->right);
    }
};
