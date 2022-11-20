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
    TreeNode* constructMaximumBinaryTree(vector<int> nums) {
        const auto first = nums.begin();
        const auto last = nums.end();
        const auto maxItr = max_element(first, last);

        TreeNode* root = new TreeNode(*maxItr);
        if (!nums.empty()) {
            if (distance(first, maxItr) >= 1) {
                root->left = constructMaximumBinaryTree(vector<int>(first, maxItr));
            }
            if (distance(maxItr + 1, last) >= 1) {
                root->right = constructMaximumBinaryTree(vector<int>(maxItr + 1, last));
            }
        }
        return root;
    }
};
