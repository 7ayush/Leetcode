class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<dp.size();i++)
        {            
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]++;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
// Recursive
class Solution {
public:
    int util(int i,vector<int>&nums,int maxi,int count)
    {
        if(i==nums.size())return count;
        if(maxi<nums[i])
        {
            return max(util(i+1,nums,nums[i],count+1),util(i+1,nums,maxi,count));
        }
        return util(i+1,nums,maxi,count);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
       return util(0,nums,INT_MIN,0);
    }
};


//Memoized
class Solution {
public:
    int util(int idx, int prev_idx, vector<int> &nums, vector<vector<int>> &dp){
        if(idx>=nums.size())return 0;
        if(dp[idx][prev_idx+1]!=-1)return dp[idx][prev_idx+1];
        if(prev_idx==-1||nums[idx]>nums[prev_idx])
        {
            return dp[idx][prev_idx+1]=max(1+util(idx+1,idx,nums,dp),util(idx+1,prev_idx,nums,dp));
        }
        return dp[idx][prev_idx+1]=util(idx+1,prev_idx,nums,dp);
        
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return util(0, -1, nums, dp);       
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {            
            if(nums[i]<=dp[dp.size()-1])
            {
                int x=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[x]=nums[i];
            }
            else
                dp.push_back(nums[i]);
        }
        return dp.size();
    }
};
