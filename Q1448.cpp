class Solution {
public:
    int util(TreeNode *root,int maxi)
    {
        if(!root)return 0;
        return (root->val>=maxi) + util(root->left,max(root->val,maxi))+util(root->right,max(root->val,maxi));
    }
    int goodNodes(TreeNode* root) {        
        return util(root,INT_MIN);
    }
};

class Solution {
public:
    int util(TreeNode *root,int maxi)
    {
        if(!root)return 0;
        int l=util(root->left,max(root->val,maxi));
        int r=util(root->right,max(root->val,maxi));
        if(root->val>=maxi)return 1+l+r;
        return l+r;
    }
    int goodNodes(TreeNode* root) {        
        return util(root,INT_MIN);
    }
};
