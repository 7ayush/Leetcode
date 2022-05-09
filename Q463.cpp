class Solution {
public:
    int getPerimeter(vector<vector<int>>& grid,int i,int j,int m,int n)
    {
        int count=0;
        if(i-1>=0&&grid[i-1][j]==1)count++;
        if(j-1>=0&&grid[i][j-1]==1)count++;
        if(i+1<m&&grid[i+1][j]==1)count++;
        if(j+1<n&&grid[i][j+1]==1)count++;        
        return 4-count;
    }
    int util(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>& visited)
    {
        if(i<0||j<0||i>=m||j>=n)return 0;
        if(visited[i][j]==1||grid[i][j]==0)return 0;
        visited[i][j]=1;
        int left=util(grid,i,j-1,m,n,visited);
        int right=util(grid,i,j+1,m,n,visited);
        int up=util(grid,i-1,j,m,n,visited);
        int down=util(grid,i+1,j,m,n,visited);
        return getPerimeter(grid,i,j,m,n)+left+right+up+down;
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));   
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)return util(grid,i,j,m,n,visited);
            }   
        }
        return 0;
    }
};
