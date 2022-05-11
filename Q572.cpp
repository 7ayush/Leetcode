class Solution {
public:
    bool identical(TreeNode *root1,TreeNode *root2)
    {
        if(!root1&&!root2)return true;
        if(!root1||!root2)return false;
        bool check=root1->val==root2->val;
        return check&&identical(root1->left,root2->left)&&identical(root1->right,root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root||!subRoot)return false;
        if(root->val==subRoot->val)
        {
            return identical(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
