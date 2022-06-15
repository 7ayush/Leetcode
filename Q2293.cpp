class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size()>1)
        {
            vector<int>nums1(nums.size()/2);
            for(int i=0;i<nums1.size();i++)
            {
                if(i&1)
                {
                    nums1[i]=max(nums[2*i],nums[2*i+1]);
                }
                else
                {
                    nums1[i]=min(nums[2*i],nums[2*i+1]);
                }
            }
            nums=nums1;
        }
        return nums[0];
    }
};
