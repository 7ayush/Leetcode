class Solution {
public:
    int mod;
    int func(int n,int prev,vector<vector<int>>&dp) 
    {
        if(n==0)return 1;
        long long int count=0;
        if(dp[n][prev]!=-1)return dp[n][prev];
        if(prev==0)    
        {
            for(int i=1;i<=5;i++)
                count=(count+func(n-1,i,dp))%mod;            
        }
        else if(prev==1)    
        {         
            count=(count+func(n-1,2,dp))%mod;         
        }
        else if(prev==2)    
        {
            count=(count+func(n-1,1,dp))%mod;         
            count=(count+func(n-1,3,dp))%mod;         
        }
        else if(prev==3)    
        {
            count=(count+func(n-1,1,dp))%mod;
            count=(count+func(n-1,2,dp))%mod;         
            count=(count+func(n-1,4,dp))%mod;
            count=(count+func(n-1,5,dp))%mod;         
        }
        else if(prev==4)    
        {
            count=(count+func(n-1,3,dp))%mod;         
            count=(count+func(n-1,5,dp))%mod;         
        }
        else if(prev==5)    
        {
            count=(count+func(n-1,1,dp))%mod;         
        }
        return dp[n][prev]=count;
    }
    int countVowelPermutation(int n) 
    {
        mod=1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
        return func(n,0,dp);
    }
};
