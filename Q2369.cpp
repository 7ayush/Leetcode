class Solution {
public:
    bool util(vector<int>&nums,int i,int n,vector<int>&dp)
    {
        if(i==n)return true;
        if(dp[i]!=-1)return dp[i];
        bool check1=false,check2=false,check3=false;
        if(i==n-1)return false;
        if(i+1<n){
            check1=nums[i+1]==nums[i] ? util(nums,i+2,n,dp) : false;
        }
        if(i+2<n)
        {
            check2=nums[i+1]==nums[i]&&nums[i+1]==nums[i+2] ? util(nums,i+3,n,dp) : false;
            check3=nums[i+1]==nums[i]+1&&nums[i+1]+1==nums[i+2] ? util(nums,i+3,n,dp) : false;
        }
        return dp[i]=check1||check2||check3;
    }
    
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return util(nums,0,nums.size(),dp);
    }
};
