// 3 states -> index where you are at, whether share is bought, how many transactions are left
class Solution {
public:
    int util(vector<int>& prices,int i,int j,bool k,vector<vector<vector<int>>>&dp)
    {
        if(i>=prices.size()||j==0)return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int res=util(prices,i+1,j,k,dp);//go ahead
        if(k==0)
        {
            res=max(res,-prices[i]+util(prices,i+1,j,true,dp));
            return dp[i][j][k]=res;   
        }
        res=max(res,prices[i]+util(prices,i+1,j-1,false,dp));
        return dp[i][j][k]=res;
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(3,vector<int>(2,-1)));
        return util(prices,0,2,0,dp);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int> left(n),right(n);
        
        //Fill 1st transaction (LEFT)
        int leftMin = prices[0];
        for(int i=1;i<n;++i)
        {
            left[i] = max(left[i-1],prices[i]-leftMin);
            leftMin = min(leftMin,prices[i]);
        }
        
        //Fill 2nd transaction (RIGHT)
        int rightMax = prices[n-1];
        for(int i=n-2;i>=0;--i)
        {
            right[i] = max(right[i+1],rightMax-prices[i]);
            rightMax = max(rightMax,prices[i]);
        }
        
        //Find the max-profit value
        int profit = right[0];
        for(int i=1;i<n;++i) profit = max(profit,left[i-1]+right[i]);
        
        return profit;
    }
};

