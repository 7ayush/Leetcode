class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int m=heights.size();
        int n=heights[0].size();
        
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>visited1(m,vector<int>(n,0));
        vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        
        queue<pair<int,int>>q;
        
        //Pacific Ocean
        for(int i=0;i<heights.size();i++)q.push({i,0});
        for(int i=0;i<heights[0].size();i++)q.push({0,i});
        
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            if(visited[x][y]==1)continue;
            visited[x][y]=1;
            for(auto d:dir)
            {
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx<0||ny<0||nx>=m||ny>=n)continue;
                if(visited[nx][ny]==1)continue;
                if(heights[x][y]<=heights[nx][ny]){
                    visited[x][y]=1;
                    q.push({nx,ny});
                }                   
            }
        }
        //Atlantic Ocean
        for(int i=0;i<heights.size();i++)q.push({i,n-1});
        for(int i=0;i<heights[0].size();i++)q.push({m-1,i});
        
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            if(visited1[x][y]==1)continue;
            visited1[x][y]=1;
            for(auto d:dir)
            {
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx<0||ny<0||nx>=m||ny>=n)continue;
                if(visited1[nx][ny]==1)continue;
                if(heights[x][y]<=heights[nx][ny]){
                    visited1[x][y]=1;
                    q.push({nx,ny});
                }                   
            }
        }
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(visited1[i][j]==1&&visited1[i][j]==visited[i][j])ans.push_back({i,j});
        return ans;
    }
};
