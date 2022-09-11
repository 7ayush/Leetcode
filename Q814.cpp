class Solution {
public:
    bool util(TreeNode *root)
    {
        if(!root)return false;
        bool left=util(root->left);
        bool right=util(root->right);
        if(!left)root->left=NULL;
        if(!right)root->right=NULL;
        return left | right | (root->val==1);
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool find=util(root);
        if(find==false)return NULL;
        else return root;
    }
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root!=NULL){
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            if(!root->left && !root->right && root->val==0)
                return NULL;
        }
        return root;
    }
};
