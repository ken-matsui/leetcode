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
    void traverse(TreeNode* node, vector<int>& res, int dep) {
        if (dep == res.size()) {
            res.push_back(node->val);
        }

        if (node->right) {
            traverse(node->right, res, dep + 1);
        }
        if (node->left) {
            traverse(node->left, res, dep + 1);
        }
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> res;
        traverse(root, res, 0);
        return res;
    }
};
