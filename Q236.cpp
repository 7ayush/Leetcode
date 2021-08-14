class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)return NULL;
        if(root->val==p->val||root->val==q->val)return root;
        TreeNode *l=lowestCommonAncestor(root->left,p,q);
        TreeNode *r=lowestCommonAncestor(root->right,p,q);
        if(l&&r)return root;
        if(!l&&!r)return NULL;
        return l?l:r;
    }
};
