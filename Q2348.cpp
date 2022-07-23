class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int count=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)ans+=count++;
            else count=1;
        }
        return ans;
    }
};
