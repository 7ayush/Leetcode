class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long>scores(edges.size(),0);
        for(int i=0;i<edges.size();i++)
        {
            scores[edges[i]]+=i;
        }
        int maxI=-1;
        long long maxi=-1;
        for(int i=0;i<edges.size();i++)
        {
            if(maxi<scores[i])
            {
                maxI=i;
                maxi=scores[i];
            }
        }
        return maxI;
    }
};
