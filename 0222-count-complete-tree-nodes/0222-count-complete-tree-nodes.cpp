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
    int depth(TreeNode* node) {
        int dep = 0;
        while (node->left) {
            node = node->left;
            ++dep;
        }
        return dep;
    }

    bool exists(int idx, int dep, TreeNode* node) {
        int left = 0;
        int right = (1 << dep) - 1;
        int pivot;
        for (int i = 0; i < dep; ++i) {
            pivot = left + (right - left) / 2;
            if (idx <= pivot) {
                node = node->left;
                right = pivot;
            } else {
                node = node->right;
                left = pivot + 1;
            }
        }
        return node != nullptr;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int dep = depth(root);
        if (dep == 0) {
            return 1;
        }

        int left = 1;
        int right = (1 << dep) - 1;
        int pivot;
        while (left <= right) {
            pivot = left + (right - left) / 2;
            if (exists(pivot, dep, root)) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        return (1 << dep) - 1 + left;
    }
};
