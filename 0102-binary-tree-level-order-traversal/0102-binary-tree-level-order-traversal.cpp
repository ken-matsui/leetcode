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
    void traverse(TreeNode* node, vector<vector<int>>& res, int dep) {
        if (!node) {
            return;
        }
        if (res.size() <= dep) {
            res.push_back({node->val});
        } else {
            res[dep].push_back(node->val);
        }
        traverse(node->left, res, dep + 1);
        traverse(node->right, res, dep + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, res, 0);
        return res;
    }
};
