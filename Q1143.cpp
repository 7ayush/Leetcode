class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)dp[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }   
            }   
        }
        return dp[m][n];
        
    }
};
//Recursive
class Solution {
public:
    int util(string text1,string text2,int i,int j)
    {
        if(i>=text1.size()||j>=text2.size())return 0;
        if(text1[i]==text2[j])
        {
            return 1+util(text1,text2,i+1,j+1);
        }
        else
        {
            return max(util(text1,text2,i+1,j),util(text1,text2,i,j+1));

        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        return util(text1,text2,0,0);
    }
};
//Memoization
class Solution {
public:
    int util(string text1,string text2,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0||j==0)return dp[i][j]=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i-1]==text2[j-1])
        {
            return dp[i][j]=1+util(text1,text2,i-1,j-1,dp);
        }
        else
        {
            return dp[i][j]=max(util(text1,text2,i-1,j,dp),util(text1,text2,i,j-1,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return util(text1,text2,m,n,dp);        
    }
};
