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
    int sum(TreeNode* root, int& count) {
        if (!root) {
            return 0;
        }
        ++count;
        return root->val + sum(root->left, count) + sum(root->right, count);
    }

    int average(TreeNode* root) {
        int count = 0;
        return sum(root, count) / count;
    }

    int averageOfSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (average(root) == root->val) {
            return 1 + averageOfSubtree(root->left) + averageOfSubtree(root->right);
        } else {
            return averageOfSubtree(root->left) + averageOfSubtree(root->right);
        }
    }
};
