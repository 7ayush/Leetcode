class Solution {
public:
    int util(int n,int size,vector<vector<int>>&dp)
    {
        if(n==0)return 0;
        if(size==0)return INT_MAX;
        if(dp[n][size]!=-1)return dp[n][size];
        int take=INT_MAX,notTake=INT_MAX;
        if(n>=size*size)
        {
            take=util(n-size*size,size,dp); 
            if(take!=INT_MAX)take++;
        }
        notTake=util(n,size-1,dp);
        take=min(take,notTake);
        return dp[n][size]=take;
    }
    int numSquares(int n) 
    {
        vector<int>squares;       
        int size=sqrt(n);
        vector<vector<int>>dp(n+1,vector<int>(size+1,-1));
        int ans=util(n,size,dp);
        return ans==INT_MAX?-1:ans;
    }
};

class Solution {
public:
    int numSquares(int n) 
    {
        vector<int>squares;       
        int size=sqrt(n);
        vector<vector<int>>dp(n+1,vector<int>(size+1,-1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=size;j++)
            {
                if(i==0)dp[i][j]=0;
                else if(j==0)dp[i][j]=INT_MAX;
                else
                {
                    int a,b;
                    if(i>=j*j){
                        a=dp[i-j*j][j];
                        if(a!=INT_MAX)a++;
                    }
                    b=dp[i][j-1];
                    dp[i][j]=min(a,b);
                }
            }
        }
        
        return dp[n][size]==INT_MAX?-1:dp[n][size];
    }
};
    
