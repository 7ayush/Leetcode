class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>dp(s.size());
        for(auto i:shifts)
        {
            if(i[2]==1)
            {
                dp[i[0]]+=1;
                if(i[1]<s.size()-1)
                {
                    dp[i[1]+1]-=1;
                }
            }
            else
            {
                dp[i[0]]-=1;
                if(i[1]<s.size()-1)
                {
                    dp[i[1]+1]+=1;
                }
            }
        }
        string ans="";
        for(int i=1;i<dp.size();i++)
        {
            dp[i]+=dp[i-1];
        }
        for(int i=0;i<dp.size();i++)
        {
            if(dp[i]<0)
            {
                int x=abs(dp[i])/26 + 1;
                dp[i]+=x*26;
            }
            char x=(s[i]-'a'+dp[i])%26+'a';
            ans+=x;
        }
        return ans;
    }
};
