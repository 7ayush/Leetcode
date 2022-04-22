class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            nums[i]+=nums[i-1];
        }
        int l=nums.size()-1;
        if(nums[l]-nums[0]==0)return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[l]-nums[i])return i;
        }
        return -1;
    }
};

