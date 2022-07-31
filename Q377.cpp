class Solution {
public:
    
    int util(vector<int>&nums,int target,vector<int>&dp)
    {
        if(target==0)return dp[target]=1;        
        if(dp[target]!=-1)return dp[target];        
        int count=0;        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=target)count+=util(nums,target-nums[i],dp);
        }
        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);        
        util(nums,target,dp);
        return dp[target];
    }
};

class Solution {
public:
    
    int util(vector<int>&nums,int target,vector<int>&dp)
    {
        if(target==0)return dp[target]=1;        
        if(dp[target]!=-1)return dp[target];        
        int count=0;        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=target)count+=util(nums,target-nums[i],dp);
            else break;
        }
        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);        
        sort(nums.begin(),nums.end());
        util(nums,target,dp);
        return dp[target];
    }
};
