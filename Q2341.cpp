class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int x=0;
        int y=0;
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        for(auto i:mp)
        {
            x+=i.second/2;
            y+=i.second%2;
        }
        return {x,y};
    }
};
