class Solution {
public:
    void dfs(vector<int>&edges,int node,int &ans,vector<int>&vis,vector<int>&temp)
    {
        int curr=1;
        while(node!=-1)
        {   
            if(vis[node]==1&&temp[node]!=0){
                ans=max(ans,curr-temp[node]);  
                return;
            }
            else if(vis[node]==1&&temp[node]==0)return;
            else 
            {
                vis[node]=1;
                temp[node]=curr;                
            }
            curr++;
            node=edges[node];
            
        }
    }
    int longestCycle(vector<int>& edges) {
        int ans=-1;
        vector<int>vis(edges.size(),0);
        vector<int>temp(edges.size(),0);
        vector<int>temp1=temp;
        for(int i=0;i<edges.size();i++)
        {
            if(!vis[i]){
                
                temp=temp1;
                dfs(edges,i,ans,vis,temp);   
            }
        }
        return ans;      
    }
};

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited;
    int ans = -1;

    void dfs(int node, int d, unordered_map<int, int>& mp){        
        visited[node] = 1;
        mp[node] = d;

        for(int child: graph[node]){
            if(visited[child] == 0){
                dfs(child, d+1, mp);
            }else if(mp.count(child)){
                // a -> b -> c -> d and if cycle if from d -> b, we reduce the distance of a
                ans = max(ans, d - mp[child] + 1);
            }
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        graph.resize(n);
        visited.resize(n, 0);

        //build graph
        for(int i=0; i<n; i++){
            if(edges[i] != -1) graph[i].push_back(edges[i]);
        }

        for(int i=0; i<n; i++){
            unordered_map<int, int> mp; //keeps track of distance
            dfs(i, 0, mp);
        }

        return ans;
    }
};
