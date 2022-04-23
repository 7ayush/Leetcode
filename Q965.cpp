class Solution {
public:
    bool check(TreeNode *root,int x)
    {
        if(!root)return true;
        if(root->val!=x)return false;
        return check(root->left,x)&&check(root->right,x);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        int x=root->val;
        bool ans=check(root,x);
        return ans;
    }
};
