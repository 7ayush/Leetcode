class Solution {
public:
    void dfs(vector<vector<int>>&adj,int i, vector<int>&visited)
    {
        if(visited[i])return;
        visited[i]=true;
        for(auto j:adj[i])
        {
            if(!visited[j])dfs(adj,j,visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>&graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(graph[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,visited);
                cout<<i<<" ";
                count++;
            }
        }
        return count;
    }
    
};
