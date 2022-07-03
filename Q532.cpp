class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int count=0;
        for(auto it:mp)
        {
            if(k>0&&mp.count(it.first-k)!=0)
            {
                count++;
            }
            else if(k==0)
            {
                if(it.second>1)count++;
            }
        }
        return count;
    }
};
