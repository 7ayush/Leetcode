class Solution {
public:
    void flatten(TreeNode *root,TreeNode **prev,TreeNode**head)
    {
        if(!root)return;
        flatten(root->left,prev,head);
        if(*prev==NULL)
        {
            *head=root;
        }
        else
        {
            root->left=NULL;
            (*prev)->right=root;
        }
        *prev=root;
        flatten(root->right,prev,head);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *prev=NULL,*head=NULL;
        flatten(root,&prev,&head);
        return head;
    }
};
