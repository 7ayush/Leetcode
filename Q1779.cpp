class Solution {
public:    
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int mindist=INT_MAX;
        int ans=-1;
        int i=0;
       for(auto it:points) 
       {
           int dist=abs(it[0]-x)+abs(it[1]-y);
           if((it[0]==x||it[1]==y)&&mindist>dist)
           {
               mindist=dist;
               ans=i;
           }
           i++;
       }
        return ans;
    }
};

