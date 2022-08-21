class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int x=abs(s[i]-s[j]);
                if(x<=k)
                {
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]++;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<int>dp(26,0);
        dp[s[0]-'a']=1;
        int ans=1;        
        for(int i=1;i<n;i++)
        {

            for(int j=0;j<26;j++)
            {
                int x=abs(s[i]-j-'a');
                if(x<=k)
                {
                    dp[s[i]-'a']=max(dp[s[i]-'a'],dp[j]);
                }
            }
            dp[s[i]-'a']++;
            ans=max(ans,dp[s[i]-'a']);
        }
        return ans;
    }
};
