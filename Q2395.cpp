class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>odd,even;
        for(int i=0;i<n-1;i++)
        {
            if(odd.find(nums[i]+nums[i+1])!=odd.end())return true;
            else odd[nums[i]+nums[i+1]]++;
        }
        return false;
    }
};
