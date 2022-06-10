class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<bool>&visited,int source,int destination)
    {
        if(visited[source])return false;
        visited[source]=true;
        if(source==destination)return true;
        for(auto it:adj[source])
        {
            if(dfs(adj,visited,it,destination))return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>>adj(n,vector<int>());
        vector<bool>visited(n,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // Debugging for printing the adjacency matrix
//         for(int it=0;it<adj.size();it++)
//         {
//             cout<<it<<": ";
//             for(int i=0;i<adj[it].size();i++)
//             {
//                 cout<<adj[it][i]<<" ";
//             }
//             cout<<endl;
//         }
    
        return dfs(adj,visited,source,destination);
    }
};
