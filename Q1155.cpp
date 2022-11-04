class Solution {
public:
    int mod;
    int util(int n,int k,int target,vector<vector<int>>&dp)
    {
        if(n==0&&target==0)return dp[n][target]=1;
        if(n==0)return dp[n][target]=0;
        if(dp[n][target]!=-1)return dp[n][target];
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            if(target-i>=0)
            {
                sum=(sum+util(n-1,k,target-i,dp))%mod;
            }
        }
        return dp[n][target]=sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        mod=1e9+7;
        return util(n,k,target,dp);
    }
};
