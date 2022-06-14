class Solution {
public:
    int util(string word1, string word2,vector<vector<int>>&dp,int m,int n)
    {
        if(m==0||n==0)return dp[m][n]= 0;
        if(dp[m][n]!=-1)return dp[m][n];
        if(word1[m-1]==word2[n-1])return dp[m][n]=1+util(word1,word2,dp,m-1,n-1);
        return dp[m][n]=max(util(word1,word2,dp,m,n-1),util(word1,word2,dp,m-1,n));
        
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int len= util(word1,word2,dp,m,n);
        return m+n-2*len;                
    }
};

IN this question we are using LCS

//DP Top down
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                                
            }   
        }
        return m+n-2*dp[m][n];                
    }
};
