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
    int sum = 0;
    
    void preorder(TreeNode* node, int cur) {
        if (!node) {
            return;
        }
        
        cur = cur * 10 + node->val;
        if (!node->left && !node->right) {
            sum += cur;
        }
        preorder(node->left, cur);
        preorder(node->right, cur);
    }
    
public:
    int sumNumbers(TreeNode* root) {
        preorder(root, 0);
        return sum;
    }
};