class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&visited,int curr)
    {
        visited[curr]=true;
        for(auto it:adj[curr])
        {
            if(!visited[it])
            {
                dfs(adj,visited,it);
            }
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(n-1>connections.size())return -1;
        vector<int>visited(n,0);
        vector<vector<int>>adj(n,vector<int>());
        for( auto it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count=0;
        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(adj,visited,i);
            }
        }
        return count-1;    
    }
};
