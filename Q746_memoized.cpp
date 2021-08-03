// Using memoized code
class Solution {
public:
    int util(vector<int>cost,int pos,vector<int>&dp)
    {
        if(pos<=2)return dp[pos]=0;
        if(dp[pos]!=-1)return dp[pos];
        return dp[pos]=min(cost[pos-2]+util(cost,pos-1,dp),cost[pos-3]+util(cost,pos-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+2,-1);
        return util(cost,cost.size()+1,dp);//size
        
    }
};
