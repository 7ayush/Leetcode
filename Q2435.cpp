class Solution {
public:
    int m,n,mod;
    int util(int i,int j,vector<vector<int>>&grid,int k,int sum,vector<vector<vector<int>>>&dp)
    {
        if(i>=m||j>=n)return 0;
         
        sum=(sum+grid[i][j])%k;
        if(dp[i][j][sum]!=-1)return dp[i][j][sum];
        if(i==m-1&&j==n-1 && sum%k==0)return dp[i][j][sum]=1;
        
        return  dp[i][j][sum]=(util(i+1,j,grid,k,sum,dp)+util(i,j+1,grid,k,sum,dp))%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        m=grid.size();
        n=grid[0].size();
        mod=1e9+7;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return util(0,0,grid,k,0,dp);
    }
};
