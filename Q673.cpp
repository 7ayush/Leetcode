class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        if(n==0) return 0;
       
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int maxL = 1;        
        int res = 0;         
        int current = 0;
        for(int i=1;i<nums.size();i++)
        {
            current = 0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[j] >= current)
                {
                    if(dp[j]==current)count[i]+=count[j];
                    else count[i] = count[j];
                    current = dp[j];                    
                }                
            }
            dp[i] = current + 1;
            maxL = max(maxL,dp[i]);
        }
        for(int i=0;i<nums.size();i++)
            if(dp[i]==maxL)res+=count[i];            

        return res;
        
    }
    
};

https://leetcode.com/problems/number-of-longest-increasing-subsequence/discuss/849276/C%2B%2B-DP-O-(-N-2-)-Solution-with-comments 
