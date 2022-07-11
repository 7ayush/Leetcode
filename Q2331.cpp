class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root)return 0;
        if(!root->left&&!root->right)return root->val;
        if(root->val==2)
        {
            return evaluateTree(root->left)||evaluateTree(root->right);
        }
        return evaluateTree(root->left)&&evaluateTree(root->right);
    }
};
