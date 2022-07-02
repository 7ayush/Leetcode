class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        int ele=INT_MIN;
        int count=0;
        for(int i=0;i<pairs.size();i++)
        {
            if(ele<pairs[i][0]){
                ele=pairs[i][1];
                count++;
            }
        }
        return count;
    }
};

// Using DP Longest increasing subsequence
class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
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

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        
        int n=pairs.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<dp.size();i++)
        {            
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0])
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
