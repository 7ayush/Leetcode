class Solution {
public:
    int util(int n,vector<int>&dp)
    {
        if(n<0)return 0;
        if(n==0||n==1)return dp[n]=n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=util(n-1,dp)+util(n-2,dp)+util(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return util(n,dp);
    }
};
