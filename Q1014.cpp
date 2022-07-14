class Solution {
public:
    int util(vector<vector<int>>&dp,vector<int>&nums,int i,int j)
    {
        if(i>=j)return INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=nums[i]+nums[j]+i-j;
        return max(ans,max(util(dp,nums,i,j-1),util(dp,nums,i+1,j)));
        
        
    }
    int maxScoreSightseeingPair(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        vector<vector<int>>dp(end+1,vector<int>(end+1,-1));
        return util(dp,nums,start,end);
    }
};


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int score=INT_MIN,n=values.size();
        int maxLeft = values[0];
        
        for(int i=1;i<n;i++){ 
            score=max(score,maxLeft+values[i]-i);
            maxLeft = max(maxLeft,values[i]+i);
        }
        
        return score;
    }
};
