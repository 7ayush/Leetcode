// DP Bottom up
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        vector<vector<int>>dp(n+1,vector<int>(maxValue+1,0));
        int mod=1e9+7;
        for(int i=1;i<=n;i++)
        {            
            for(int j=1;j<=maxValue;j++)
            {
                if(i==1||j==1){
                    dp[i][j]=1;
                    continue;
                }                
                long long ans=0;
                for(int k=1;k<=j/2;k++)
                {                    
                    if(j%k==0)
                    {
                        ans=(ans+dp[i-1][k])%mod;
                    }
                }
                ans=(ans+dp[i-1][j])%mod;
                dp[i][j]+=ans;
            }
        }
        long long int ans=0;
        for(int j=1;j<=maxValue;j++)
        {            
            ans=(ans+dp[n][j])%mod;
        }
        return ans;        
    }
};
