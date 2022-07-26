class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        map<vector<int>,int>mp;
        for(auto i:grid)mp[i]++;
        for(int i=0;i<grid[0].size();i++)
        {
            vector<int>temp;
            for(int j=0;j<grid.size();j++)
            {
                temp.push_back(grid[j][i]);
            }
            auto it=mp.find(temp);
            if(it!=mp.end())count+=it->second;
        }
        return count;
    }
};
