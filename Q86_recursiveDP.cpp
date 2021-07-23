class Solution {
public:

    int util(vector<int>nums,int sum,int n,vector<vector<int>>&dp)
    {
        if(sum==0)return dp[n][sum]=1;
        if(n==0)  return dp[n][sum]=0;
        
        if(dp[n][sum]!=-1)return dp[n][sum];
        
        if(nums[n-1]<=sum)
        {
            return dp[n][sum]=util(nums,sum-nums[n-1],n-1,dp)+util(nums,sum,n-1,dp);
        }
        else
        {
            return dp[n][sum]=util(nums,sum,n-1,dp);
        }                
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {         
        if(nums.size()==1&&abs(nums[0])!=abs(target))
        {
            return 0;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        int half=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(half+1,-1));
        int ans=(sum-target)/2;
        return util(nums,ans,nums.size(),dp);        
    }
    
    
};
