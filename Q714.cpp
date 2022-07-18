class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buyState=-prices[0];
        int sellState=0;
        for(int i=1;i<prices.size();i++)
        {
            buyState=max(-prices[i]+sellState,buyState);
            sellState=max(buyState+prices[i]-fee,sellState);
        }
        return sellState;
        
    }
};


class Solution {
public:
    int solve(vector<int>&price,int fee,int i,int n,int buy,vector<vector<int>>&dp){
        if(i==n)
            return 0;
        int x=0,y=0;
        if(dp[i][buy]!=INT_MIN)
            return dp[i][buy];
        if(buy==0){
            x=solve(price,fee,i+1,n,buy,dp);
            y=-price[i]+solve(price,fee,i+1,n,1,dp);
        }else{
            x=solve(price,fee,i+1,n,buy,dp);
            y=solve(price,fee,i+1,n,0,dp)+price[i]-fee;
        }
        return dp[i][buy]=max(x,y);
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> out(prices.size()+1,vector<int>(2,INT_MIN));
        return solve(prices,fee,0,prices.size(),0,out);
    }
};
