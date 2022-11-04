class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)return NULL;
        if(depth==1)
        {
            TreeNode *temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        if(depth==2)
        {
            TreeNode *temp1=new TreeNode(val);
            TreeNode *temp2=new TreeNode(val);
            temp1->left=root->left;
            temp2->right=root->right;
            root->left=temp1;
            root->right=temp2;
            return root;
        }
        root->left=addOneRow(root->left,val,depth-1);
        root->right=addOneRow(root->right,val,depth-1);
        return root;
    }
};
