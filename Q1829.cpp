class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int>ans(nums.size());
        int max=pow(2,maximumBit)-1;
        for(int i=1;i<nums.size();i++)
        {
            nums[i]^=nums[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            int k=max^nums[i];
            ans[n-i-1]=k;
        }
        return ans;
    }
};
