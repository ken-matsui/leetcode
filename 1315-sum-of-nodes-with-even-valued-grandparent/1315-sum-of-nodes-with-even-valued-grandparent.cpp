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
public:
    int sumGrandchildren(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sum = 0;
        if (root->left) {
            if (root->left->left) {
                sum += root->left->left->val;
            }
            if (root->left->right) {
                sum += root->left->right->val;
            }
        }
        if (root->right) {
            if (root->right->left) {
                sum += root->right->left->val;
            }
            if (root->right->right) {
                sum += root->right->right->val;
            }
        }
        return sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        if (!root) {
            return 0;
        }

        const int sum =
            sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
        if (root->val % 2 == 0) {
            return sumGrandchildren(root) + sum;
        } else {
            return sum;
        }
    }
};
