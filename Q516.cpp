class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)dp[i][j]=0;
                else if(s[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }   
            }   
        }
        return dp[m][m];
    }
};
