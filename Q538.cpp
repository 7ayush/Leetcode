// First we are iterating over the right node, maintaining a sum variable and updating it regularly.
// Adding the value to sum variable consecutively
class Solution {
public:
    void modify(TreeNode *root,int *sum)
    {
        if(!root)return;
        modify(root->right,sum);
        root->val=root->val+*sum;
        *sum=root->val;
        modify(root->left,sum);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        modify(root,&sum);
        return root;
    }
};
