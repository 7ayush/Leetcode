class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int l=0;
        int r=0;
        long long sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(l<=r && sum*(r-l+1)>=k)
            {
                sum-=nums[l++];
            }            
            int count=r-l+1;
            ans+=count;
            r++;
        }

        return ans;
    }
};
