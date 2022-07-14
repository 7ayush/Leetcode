class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++)nums[i]+=nums[i-1];
        int ans=nums[k-1];
        for(int i=k;i<nums.size();i++)ans=max(nums[i]-nums[i-k],ans);
        return (double)ans/k;
    }
};
