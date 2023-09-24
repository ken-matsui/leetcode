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
    vector<string> res;
    
    void preorder(TreeNode* node, string path) {
        if (!node) {
            return;
        }
        
        path += "->" + to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(path);
        }
        
        preorder(node->left, path);
        preorder(node->right, path);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return {};
        }
        if (!root->left && !root->right) {
            return {to_string(root->val)};
        }

        string path = to_string(root->val);
        preorder(root->left, path);
        preorder(root->right, path);
        return res;
    }
};
