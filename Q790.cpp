class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9+7;
        if(n == 1 || n == 2) return n;
        vector<long>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]*2 + dp[i-3];
            dp[i]%=mod;
        }
        return dp[n];
    }
};
