// Return the index of 2 numbers whose sum equals to a target
// Insertion->O (logn) access->O(logn)
// Unordered Map can also be used
#include "bits.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                return {i,mp[target-nums[i]]};
            }
            mp[nums[i]]=i;
        }
        return {};
        
    }
};
