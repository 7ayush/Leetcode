class Solution {
public:
    int util(TreeNode *root,int &maxi)
    {
        if(!root)return 0;
        int l=util(root->left,maxi);
        int r=util(root->right,maxi);
        if(l<0) l=0;
        if(r<0) r=0;
        maxi=max(root->val+l+r,maxi); 
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        util(root,ans);
        return ans;
    }
};
