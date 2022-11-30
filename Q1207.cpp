class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp,mp1;
        for(auto i:arr)
        {
            mp[i]++;
        }
        for(auto [a,b]:mp)
        {
            mp1[b]++;
        }
        return mp.size()==mp1.size();
    }
};
