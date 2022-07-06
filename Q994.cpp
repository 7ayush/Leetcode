class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        int oneCount=0;
        int twoCount=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2){
                    q.push({i,j});
                    twoCount++;
                }
                if(grid[i][j]==1)oneCount++;
            }   
        }
        if(twoCount==0&&oneCount==0)return 0;

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while(!q.empty())
        {
            int x=q.size();
            bool flag=false;

            while(x--)
            {
                auto it=q.front();
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int nr=it.first+dir[i][0];
                    int nc=it.second+dir[i][1];
                    if(nr<0||nc<0||nr>=m||nc>=n)continue;
                    if(grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        oneCount--;
                    }                
                }
                
            } 
            count++;
        }
        return oneCount==0 ?count-1:-1;
        // return count-1;

    }
};
