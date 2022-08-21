class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        if(a[0]!=b[0])return a[0]<b[0];
        return a[1]<b[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int>dp(n,0);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
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

    int maxEnvelopes(vector<vector<int>>& envelopes) {

      sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
      });
      
      vector<int> dp;
      for (auto envelope: envelopes) {
        auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
        if (it == dp.end()){
          dp.push_back(envelope[1]);
        } else {
          *it = envelope[1];
        }
      }
      return dp.size();
    }
};
