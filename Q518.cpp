class Solution {
public:
    int util(vector<int>& coin, int amount,int i,vector<vector<int>>&dp)
    {
        if(amount==0)return 1;
        if(i>=coin.size())return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int count1=0;
        int count2=0;
        if(amount-coin[i]>=0)
        {
            count1=util(coin,amount-coin[i],i,dp);//take
        }
        count2=util(coin,amount,i+1,dp);//not take
        return dp[i][amount]=count1+count2;
    }
    int change(int amount,vector<int>&coin) {
        vector<vector<int>>dp(coin.size(),vector<int>(amount+1,-1));
        int ans=util(coin,amount,0,dp);
        return ans;
    }
};
