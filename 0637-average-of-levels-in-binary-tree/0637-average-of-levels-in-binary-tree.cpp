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
    vector<vector<int>> values;

    void rec(TreeNode* node, int level) {
        if (!node) {
            return;
        }

        if (values.size() <= level) {
            values.push_back(vector<int>{});
        }

        values[level].push_back(node->val);
        rec(node->left, level + 1);
        rec(node->right, level + 1);
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) {
            return {};
        }

        rec(root, 0);
        vector<double> result;
        for (const auto& vec : values) {
            double val = 0.;
            for (const int v : vec) {
                val += static_cast<double>(v);
            }
            result.push_back(val / static_cast<double>(vec.size()));
        }
        return result;
    }
};
