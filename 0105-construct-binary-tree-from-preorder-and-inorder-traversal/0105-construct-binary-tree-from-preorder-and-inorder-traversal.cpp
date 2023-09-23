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
    int preorderIdx = 0;
    unordered_map<int, int> inorderIdx;
    
    TreeNode* createTree(const vector<int>& preorder, const int left, const int right) {
        if (left > right) {
            return nullptr;
        }
        
        int rootVal = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = createTree(preorder, left, inorderIdx[rootVal] - 1);
        root->right = createTree(preorder, inorderIdx[rootVal] + 1, right);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIdx[inorder[i]] = i;
        }
        return createTree(preorder, 0, preorder.size() - 1);
    }
};