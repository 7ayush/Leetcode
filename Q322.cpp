

class Solution {
public:
    int util(vector<int>& coin, int amount,int i,vector<vector<int>>&dp)
    {
        if(amount==0)return 0;
        if(i>=coin.size())return INT_MAX;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int count1=INT_MAX;
        int count2=INT_MAX;
        if(amount-coin[i]>=0)
        {
            count1=util(coin,amount-coin[i],i,dp);//take
            if(count1<INT_MAX)count1++;
        }
        count2=util(coin,amount,i+1,dp);//not take
        count1=min(count1,count2);
        return dp[i][amount]=count1;
    }
    int coinChange(vector<int>& coin, int amount) {
        vector<vector<int>>dp(coin.size(),vector<int>(amount+1,-1));
        int ans=util(coin,amount,0,dp);
        return ans==INT_MAX?-1:ans;
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        // creating the base dp array, with first value set to 0
        int dp[++n];
        dp[0] = 0;
        // more convenient to have the coins sorted
        sort(begin(coins), end(coins));
        // populating our dp array
        for (int i = 1; i < n; i++) {
            // setting dp[0] base value to 1, 0 for all the rest
            dp[i] = INT_MAX;
            for (int c: coins) {
                if (i - c < 0) break;
                // if it was a previously not reached cell, we do not add use it
                if (dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[--n] == INT_MAX ? -1 : dp[n];
    }
};

