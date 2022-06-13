class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int left=countNodes(root->left);
        int right=countNodes(root->right);
        return 1+left+right;
        
    }
};


class Solution 
{
    public:
    int height(TreeNode *root) 
    {
            return root == NULL ? -1 : 1 + height(root->left);
    }
        int countNodes(TreeNode *root) 
        {
            int h = height(root);
            return h < 0 ? 0 :
                height(root->right) == h-1 ? (1 << h) + countNodes(root->right): 
                (1 << h-1) + countNodes(root->left);
        }
};
