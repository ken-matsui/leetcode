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
    bool traverse(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (!node) {
            return true;
        }
        
        if (low && node->val <= low->val) {
            return false;
        }
        if (high && node->val >= high->val) {
            return false;
        }
        return traverse(node->left, low, node) && traverse(node->right, node, high);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return traverse(root, nullptr, nullptr);
    }
};