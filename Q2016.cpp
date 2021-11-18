class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxdiff=-1;
        int idx=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[idx]>0)
            {
                maxdiff=max(maxdiff,nums[i]-nums[idx]);
            }
            else
            {
                idx=i;
            }
        }
        return maxdiff;
    }
};
