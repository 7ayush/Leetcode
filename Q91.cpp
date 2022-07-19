class Solution {
public:
    int util(string s,int i,vector<int>&dp)
    {
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        int ans=0;        
        ans+=util(s,i+1,dp);
        if(s[i]=='0')return dp[i]=0;
        if(i+1<s.size())
        {
            if(stoi(s.substr(i,2))<=26)
            {
                ans+=util(s,i+2,dp);
            }
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return util(s,0,dp);
    }
};
