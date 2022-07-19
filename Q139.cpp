// two parameters we are considering
// 1) the index we are at
// 2) length of string we have considered so far at that index
class Solution {
public:
    bool util(string s,map<string,int>&mp,string temp,int i,vector<vector<int>>&dp)
    {
        if(i==s.size())
        {
            if(temp==""||mp[temp]==1)return true;
            return false;
        }
        int n=temp.size();
        if(dp[i][n]!=-1)return dp[i][n];        
        temp+=s[i];
        if(mp[temp]==1)
        {       
            return dp[i][n]=util(s,mp,"",i+1,dp)||util(s,mp,temp,i+1,dp);
        }
        return dp[i][n]=util(s,mp,temp,i+1,dp);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        for(string s:wordDict)mp[s]=1;
        vector<vector<int>>dp(s.size(),vector<int>(s.size()+1,-1));
        return util(s,mp,"",0,dp);
    }
};
