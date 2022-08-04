class Solution {
public:
    int util(vector<int>&nums,int sum,int target,int i,map<pair<int,int>,int>&mp)
    {
        if(i==nums.size())
        {
            if(sum==target)return 1;
            return 0;
        }
        if(mp.find({i,sum})!=mp.end())return mp[{i,sum}];
        int plus=util(nums,sum+nums[i],target,i+1,mp);
        int minus=util(nums,sum-nums[i],target,i+1,mp);
        return mp[{i,sum}]=plus+minus;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>mp;
        return util(nums,0,target,0,mp);
    }
};
