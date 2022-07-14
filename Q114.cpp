class Solution {
public:
    TreeNode* temp=NULL;
    void flatten(TreeNode* root) {

        if(!root)return;
        TreeNode *l=root->left;
        TreeNode *r=root->right;
        
        root->left=NULL;
        root->right=NULL;
        if(temp==NULL) temp=root; 
        else
        {
            temp->right=root;
            temp->left=NULL;
            temp=root;
        }
        if(l)flatten(l);
        if(r)flatten(r);        
    }
};
