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
    void calcSumBST(const TreeNode const* root, const int& low, const int& high, int& sum) {
        if (root == nullptr) {
            return;
        }
        const int val = root->val;

        if (val == low) { // only need to see the right
            sum += val;
            calcSumBST(root->right, low, high, sum);
        } else if (val == high) { // only need to see the left
            sum += val;
            calcSumBST(root->left, low, high, sum);
        } else if (val > low && val < high) {
            sum += val;
            calcSumBST(root->left, low, high, sum);
            calcSumBST(root->right, low, high, sum);
        } else if (val < low) { // only need to see the right
            calcSumBST(root->right, low, high, sum);
        } else if (val > high) { // only need to see the left
            calcSumBST(root->left, low, high, sum);
        }
        return;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        calcSumBST(root, low, high, sum);
        return sum;
    }
};
