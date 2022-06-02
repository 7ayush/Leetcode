class Solution {
public:
    int sumEvenGrandparent(TreeNode* root,TreeNode *parent=NULL) 
    {
        if(!root)return 0;
        int left=sumEvenGrandparent(root->left,root);
        int right=sumEvenGrandparent(root->right,root);
        int sum=0;
        if(parent&&parent->val%2==0)
        {            
            if(root->left)sum+=root->left->val;
            if(root->right)sum+= root->right->val;
        }
        return left+right+sum;
    }
};
