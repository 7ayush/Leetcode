class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>points;
        for(auto i:circles)
        {
            int left=i[0]-i[2];
            int right=i[0]+i[2];
            int up=i[1]+i[2];
            int down=i[1]-i[2];
            int x=i[0],y=i[1];    
            int r=i[2];
            for(int j=left;j<=right;j++)
            {
                for(int k=down;k<=up;k++)
                {
                    int dist=(x-j)*(x-j)+(y-k)*(y-k);
                    if(dist<=r*r)
                    {
                        points.insert({j,k});
                    }
                }               
            }
        }
        int x=points.size();
        return x;
    }
};
