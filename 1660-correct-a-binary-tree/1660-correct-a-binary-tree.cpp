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
    unordered_set<int> visited;
    
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        if (root->right && visited.find(root->right->val) != visited.end()) {
            // invalid node
            return nullptr;
        }
        visited.insert(root->val);

        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);
        return root;
    }
};