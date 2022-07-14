class Solution {
public:
    long util(TreeNode *root)
    {
        if(!root||!root->left)return LONG_MAX;        
        long left= root->left-> val==root->val ? util(root->left) : root->left->val;
        long right=root->right->val==root->val ? util(root->right) : root->right->val;
        
        return min(left,right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        long ans=util(root);
        return ans==LONG_MAX ? -1:ans;
    }
};
