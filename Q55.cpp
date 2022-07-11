//By just checking whether we are able to reach or not
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable=0;
        for(int i=0;i<=maxReachable;i++)
        {
           if(maxReachable>=nums.size()-1)return true;
            maxReachable=max(maxReachable,i+nums[i]);
        }
        return maxReachable>=nums.size()-1;
    }
};

//Recursive
class Solution {
public:
    bool util(vector<int>& nums,int i)
    {
        if(i>=nums.size()-1)return true;
        if(nums[i]==0)return false;
        for(int j=1;j<=nums[i];j++)
        {
            if(util(nums,i+j))return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return util(nums,0);
    }
};

//Memoization
class Solution {
public:
    bool util(vector<int>& nums,int i,vector<int>&dp)
    {
        if(i>=nums.size()-1)return true;
        if(dp[i]!=-1)return dp[i];
        if(nums[i]==0)return dp[i]=false;
        for(int j=1;j<=nums[i];j++)
        {
            if(util(nums,i+j,dp))return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return util(nums,0,dp);
    }
};
