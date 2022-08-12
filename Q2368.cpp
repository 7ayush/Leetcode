class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,int>mp;
        for(auto i:restricted)
        {
            mp[i]++;
        }
        unordered_map<int,vector<int>>mp1;
        for(auto i:edges)
        {
            if(mp.find(i[0])!=mp.end()||mp.find(i[1])!=mp.end())continue;
            else{
                mp1[i[0]].push_back(i[1]);
                mp1[i[1]].push_back(i[0]);
            }
        }
        queue<int>q;
        vector<int>vis(n,0);
        
        if(!mp[0])q.push(0);
        else return 0;
        
        vis[0]=1;
        int count=0;
        
        while(!q.empty())
        {
            int x=q.size();
            while(x--)
            {
                auto it=q.front();
                q.pop();
                count++;
                for(auto i:mp1[it])
                {
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i]=true;
                    }
                }
            }
        }
        return count;
    }
};
