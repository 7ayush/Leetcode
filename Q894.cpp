class Solution {
public:
    vector<TreeNode*>util(int n,vector<vector<TreeNode*>>&dp)
    {
        if(dp[n].size()!=0)return dp[n];        
        vector<TreeNode*>ans;
        for(int i=1;i<=n;i+=2)
        {
            int j=n-i-1;
            if(j%2==1)
            {                
                auto l=util(i,dp);    
                auto r=util(j,dp);
                for(auto x:l)
                {                    
                    for(auto y:r)
                    {
                        TreeNode *root=new TreeNode(0);
                        root->left=x;
                        root->right=y;
                        ans.push_back(root);
                    }
                }
            }            
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>>dp(n+1);
        TreeNode *root=new TreeNode(0);        
        dp[1]={root};
        return util(n,dp);        
    }
};
