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
    vector<vector<int>> res;

    void preorder(TreeNode* node, vector<int> path, int sum,
                  const int targetSum) {
        if (!node) {
            return;
        }

        sum += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            if (sum == targetSum) {
                res.push_back(path);
            }
        }
        preorder(node->left, path, sum, targetSum);
        preorder(node->right, path, sum, targetSum);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preorder(root, {}, 0, targetSum);
        return res;
    }
};
