class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>w,l;
        vector<vector<int>>ans(2);
        for(auto i:matches)
        {
            w[i[0]]++;
            l[i[1]]++;
        }
        for(auto i:w)
        {
            if(l.find(i.first)==l.end())
            {
                ans[0].push_back(i.first);
            }
        }
        for(auto i:l)
        {
            if(i.second==1)
            {
                ans[1].push_back(i.first);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;


    }
};
