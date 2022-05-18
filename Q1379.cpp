class Solution {
public:
    TreeNode *ans=NULL;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned == NULL)
            return NULL;
        if (cloned->val == target->val)return cloned;
        TreeNode *left=getTargetCopy(original,cloned->left,target);
        TreeNode *right=getTargetCopy(original,cloned->right,target);
        if(left)return left;
        return right;
    }
};
