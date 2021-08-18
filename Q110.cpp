class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int diff=abs(maxDepth(root->left)-maxDepth(root->right));
        bool ans=diff<=1?true:false;
        if(!ans)return ans;
        return ans&&isBalanced(root->left)&&isBalanced(root->right);
        
    }
};
class Solution {
public:
    bool flag=true;
    int height(TreeNode *root)
    {
        if(!root)return 0;
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)>1)flag=false;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return flag;
        
        
    }
};
