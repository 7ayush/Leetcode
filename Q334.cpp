class Solution {
public:
    
    bool increasingTriplet(vector<int>& nums) {
        vector<int>smallerLeft;
        vector<int>greaterRight(nums.size());
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(mini>=nums[i])
            {
                mini=nums[i];
                smallerLeft.push_back(0);
            }
            else
            {
                smallerLeft.push_back(1);
            }
        }
        int maxi=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(maxi<=nums[i])
            {
                maxi=nums[i];
                greaterRight[i]=0;
            }
            else
            {
                greaterRight[i]=1;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(smallerLeft[i]&&greaterRight[i])return true;
        }
        return false;
    }
};

//TLE
class Solution {
public: 
    bool increasingTriplet(vector<int>& nums) {
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
        return ans>=3;
    }
};

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

