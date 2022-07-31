class Solution {
public:
    
    int helper(vector<int>&dp, int &n, int tar)
    {
        if(dp[tar-1]) return dp[tar-1];
        int ans = tar==n ? 0 : tar;
        for(int i=1; i<tar; ++i)ans=max(ans, helper(dp,n,tar-i)*helper(dp,n,i));
        return dp[tar-1]=ans;
    }
    int integerBreak(int n) {        
        vector<int>dp(n);
        dp[0] = 1;
        return helper(dp, n, n);
    }
};
