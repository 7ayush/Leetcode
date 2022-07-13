class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         if(k<=1)return 0;
        int ans=0,left=0;
        long long int prod=1;
        for(int right=0;right<nums.size();right++)
        {
            prod=prod*nums[right];
            while(prod>=k)prod=prod/nums[left++];
            ans+=right-left+1;
        }
        return ans;
    
    }
};
