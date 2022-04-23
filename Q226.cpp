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
    
    TreeNode* invertTree(TreeNode* root) 
    {
         if(!root) return NULL;
        
        // First we want to swap the children
        // of the current root node we are at.
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // After that we just do a basic
        // preorder traversal of the tree.
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
