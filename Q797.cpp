class Solution {
public:
    void dfs(int i, vector<vector<int>>&ans,vector<int>temp,vector<vector<int>>& graph)
    {
        temp.push_back(i);
        if(i+1==graph.size()){
            ans.push_back(temp);
            return;
        }
        for(auto it:graph[i])
        {
            dfs(it,ans,temp,graph);
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        dfs(0,ans,{},graph);
        return ans;
    }
};
