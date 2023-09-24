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
    double minDiff = DBL_MAX;
    int closeVal = INT_MAX;
    
public:
    int closestValue(TreeNode* root, double target) {
        if (!root) {
            return closeVal;
        }
        double diff = abs(root->val - target);
        if (diff < minDiff) {
            minDiff = diff;
            closeVal = root->val;
        } else if (diff == minDiff) {
            closeVal = min(closeVal, root->val);
        }

        if (root->val == target) {
            return root->val;
        } else if (root->val < target) {
            return closestValue(root->right, target);
        } else {
            return closestValue(root->left, target);
        }
    }
};