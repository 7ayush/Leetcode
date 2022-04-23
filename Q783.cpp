class Solution {
public:
    void iterate(TreeNode *root,TreeNode **prev,int *minDiff)
    {
        if(!root)return ;
        iterate(root->left,prev,minDiff);
        if(*prev)
            *minDiff=min(*minDiff,root->val-(*prev)->val);
        *prev=root;
        iterate(root->right,prev,minDiff);
    }
    int minDiffInBST(TreeNode* root) {
        int minDiff=INT_MAX;
        TreeNode *prev=NULL;
        iterate(root,&prev,&minDiff);
        return minDiff;
        
    }
};
