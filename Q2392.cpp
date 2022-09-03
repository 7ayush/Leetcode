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
    bool isCyclic(vector<vector<int>>&adj) {
        // code here
        int V=adj.size();
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
	vector<int> topoSort(vector<vector<int>>&adj) 
	{
	    // code here
        int V=adj.size();
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
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>>matrix(k,vector<int>(k,0));
        
        vector<vector<int>>rowGraph(k);
        vector<vector<int>>colGraph(k);
        
        vector<int>rows(k);
        vector<int>cols(k);
        
        for(auto i:rowConditions)rowGraph[i[0]-1].push_back(i[1]-1);
        for(auto i:colConditions)colGraph[i[0]-1].push_back(i[1]-1);
        
        if(isCyclic(rowGraph))return {};
        if(isCyclic(colGraph))return {};
        
        vector<int>rows1=topoSort(rowGraph);
        vector<int>cols1=topoSort(colGraph);        
        
        // for(auto i:rows1)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:cols1)cout<<i<<" ";
        // cout<<endl;
        
        for(int i=0;i<rows1.size();i++)
        {
            rows[rows1[i]]=i;
            cols[cols1[i]]=i;
        }
        // for(auto i:rows)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:cols)cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<rows.size();i++)
        {
            matrix[rows[i]][cols[i]]=i+1;
        }
        return matrix;
    }
};
