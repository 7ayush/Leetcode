class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<3)return *max_element(nums.begin(),nums.end());
        nums[2]+=nums[0];
        for(int i=3;i<nums.size();i++)
        {
            nums[i]+=max(nums[i-2],nums[i-3]);
        }
        return max(nums[nums.size()-1],nums[nums.size()-2]);
    }
};
