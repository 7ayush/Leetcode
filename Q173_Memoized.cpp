class Solution {
public:
    int util(int n,vector<int>&dp)
    {
        if(n==1)return dp[n]=0;
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i<n;i++)
        {
            if(n%i==0)
            {
                if(util(n-i,dp)==false)return dp[n]=1;
            }
        }
        return dp[n]=0;
        
    }
    bool divisorGame(int n) 
    {
        vector<int>dp(n+1,-1);
         return util(n,dp);   
    }
};



//Optimised further
class Solution {
public:
    int util(int n,vector<int>&dp)
    {
        if(n==1)return dp[n]=0;
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i*i<n;i++)
        {
            if(n%i==0)
            {
                if(util(n-i,dp)==false)return dp[n]=1;
            }
        }
        return dp[n]=0;
        
    }
    bool divisorGame(int n) 
    {
        vector<int>dp(n+1,-1);
         return util(n,dp);   
    }
};

class Solution {
public:
    bool divisorGame(int n) 
    {
        return n%2==0;
    }
};
