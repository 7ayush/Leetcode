class Solution {
public:
    int util(TreeNode *root,vector<int>vis)
    {
        if(!root)return 0;
        vis[root->val]++;
        if(!root->left&&!root->right)
        {
            int countOdd=0;
            for(int i=0;i<10;i++)
            {
                if(vis[i]%2==1)countOdd++;
            }
            return countOdd<=1;
        }
        return util(root->left,vis)+util(root->right,vis);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>vis(10,0);
        return util(root,vis);
    }
};
