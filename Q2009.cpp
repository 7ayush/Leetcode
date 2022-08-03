class Solution {
public:
    int binarySearch(vector<vector<int>>&nums,int idx,int n)
    {
        int start=idx+1;
        int end=nums.size()-1;
        int ans=nums[idx][0]+n;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid][0]>ans)
            {
                if(mid-1>=start&&nums[mid-1][0]<ans)return mid;
                else end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return start;
    }
    int minOperations(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<int>>dp;
        map<int,int>mp;
        for(auto i:nums)mp[i]++;
        for(auto [x,y]:mp) dp.push_back({x,y});
        
        
        int ans=INT_MAX;        
        for(int i=dp.size()-2;i>=0;i--)
        {
            dp[i][1]+=dp[i+1][1];
        }
        for(int i=0;i<dp.size();i++)   
        {
            int idx=binarySearch(dp,i,nums.size()-1);
            int x=(dp[i][1]-dp.size()+i);
            x=(dp[0][1]-dp[i][1])+(dp.size()-idx)+x;
            ans=min(ans,x);
        }
        return ans;
    }
};

