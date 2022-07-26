class Solution {
public:
    int util(string word1,string word2,int i,int j,vector<vector<int>>&dp)
    {
        if(j==word2.size())return word1.size()-i;
        if(i==word1.size())return word2.size()-j;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])return dp[i][j]=util(word1,word2,i+1,j+1,dp);
        
        int del=1+util(word1,word2,i+1,j,dp);
        int update=1+util(word1,word2,i+1,j+1,dp);
        int insert=1+util(word1,word2,i,j+1,dp);
        
        int mini=min(del,min(update,insert));
        
        return dp[i][j]=mini;
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return util(word1,word2,0,0,dp);
    }
};
