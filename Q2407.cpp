class Solution {
public:
    int lengthOfLIS(vector<int>& nums,int k) 
    {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<dp.size();i++)
        {            
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i]&&nums[i]-nums[j]<=k)
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

