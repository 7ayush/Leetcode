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
    int depth(TreeNode *root)
    {
        if(!root)return INT_MAX;
        if(!root->left&&!root->right)return 1;
        return 1+min(depth(root->left),depth(root->right));
    }
    int minDepth(TreeNode* root) {
        int d=depth(root);
        return d==INT_MAX?0:d;
    }
};
