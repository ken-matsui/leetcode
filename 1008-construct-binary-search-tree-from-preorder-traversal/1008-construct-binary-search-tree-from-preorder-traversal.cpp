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
    TreeNode* build(const vector<int>& v, int& i, const int val) {
        if (i == v.size() || v[i] > val) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(v[i]);
        ++i;
        root->left = build(v, i, root->val);
        root->right = build(v, i, val);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        int i = 1;
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, 1001);

        return root;
    }
};
