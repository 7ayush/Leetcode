// All the nodes with inDegree 0 are to be taken
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int>inDegree(n,0);
        for(auto i:edges)
        {
            inDegree[i[1]]++;
        }
        vector<int>ans;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)ans.push_back(i);
        }
        return ans;
        
    }
};
