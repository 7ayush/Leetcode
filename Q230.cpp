class Solution 
{
public:
    void inOrder(TreeNode *root,int *k,int *ans)
    {
        if(!root||*k<0)return;
        inOrder(root->left,k,ans);
        *k=*k-1;
        if(*k==0){
            *ans=root->val;
            return;
        }        
        inOrder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        inOrder(root,&k,&ans);
        return ans;
        
    }    
};
