class Solution {
public:
    void dfs(vector<vector<int>>&grid,int r,int c,int *count,vector<vector<bool>>&visited,int i,int j)
    {
        if(i<0||j<0||i>=r||j>=c)return;        
        if(grid[i][j]==1&&!visited[i][j])
        {
            *count=*count+1;
            visited[i][j]=true;
            dfs(grid,r,c,count,visited,i+1,j);
            dfs(grid,r,c,count,visited,i-1,j);
            dfs(grid,r,c,count,visited,i,j+1);
            dfs(grid,r,c,count,visited,i,j-1);
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,0));
        int mx=0;
        int count;
        for(int i=0;i<r;i++)
        {            
            for(int j=0;j<c;j++)
            {
                count=0;
                if(grid[i][j])dfs(grid,r,c,&count,visited,i,j);
                mx=max(count,mx);
            }
            
        }
        return mx;
    }
};
