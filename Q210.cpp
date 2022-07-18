class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&dfsVis,int curr)
    {
        vis[curr]=true;
        dfsVis[curr]=true;
        
        for(auto it:adj[curr])
        {
            if(!vis[it]&&dfs(adj,vis,dfsVis,it))
            {
                return true;                
            }
            else if(dfsVis[it]) return true;
        }
        dfsVis[curr]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>>&adj) {
        // code here
        vector<int>vis(V,false);
        vector<int>dfsVis(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i]&&dfs(adj,vis,dfsVis,i))return true;
        }
        return false;
    }
    void dfs1(vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s,int curr)
	{
	    if(visited[curr])return;
	    visited[curr]=true;
	    for(auto it:adj[curr])
	    {
	        dfs1(adj,visited,s,it);
	    }
	    s.push(curr);
	}
	vector<int> topoSort(int V, vector<vector<int>>&adj) 
	{
	    vector<int>vec;
	    stack<int>s;
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++)
	    {
	        dfs1(adj,visited,s,i);
	    }
	    while(!s.empty())
	    {
	        vec.push_back(s.top());
	        s.pop();
	    }
	    return vec;
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it :prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        if(isCyclic(numCourses,adj))return {};        
        return topoSort(numCourses,adj);
    }
};


