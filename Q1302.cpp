class Solution {
public:
    void util(TreeNode *root,int &sum,int height,int &maxHeight)
    {
        if(!root)return;
        if(!root->left&&!root->right)
        {
            if(maxHeight<height)
            {
                sum=root->val;
                maxHeight=height;
            }
            else if(maxHeight==height)
            {
                sum+=root->val;
            }
            
        }
        util(root->left,sum,height+1,maxHeight);
        util(root->right,sum,height+1,maxHeight);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int maxHeight=0;
        util(root,sum,0,maxHeight);
        return sum;
    }
};
