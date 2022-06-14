class Solution {
public:
    bool isValid(int i,int j,int m,int n)
    {
        if(i<0||j<0||i>=m||j>=n)return false;
        return true;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>&visited,int i,int j,int m,int n,int pi,int pj)
    {
        if(visited[i][j])return;
        visited[i][j]=true;
        if(isValid(i-1,j,m,n)&&(i-1!=pi||j!=pj)&&grid[i-1][j]=='1') dfs(grid,visited,i-1,j,m,n,i,j);
        if(isValid(i+1,j,m,n)&&(i+1!=pi||j!=pj)&&grid[i+1][j]=='1') dfs(grid,visited,i+1,j,m,n,i,j);
        if(isValid(i,j-1,m,n)&&(i!=pi||j-1!=pj)&&grid[i][j-1]=='1') dfs(grid,visited,i,j-1,m,n,i,j);
        if(isValid(i,j+1,m,n)&&(i!=pi||j+1!=pj)&&grid[i][j+1]=='1') dfs(grid,visited,i,j+1,m,n,i,j);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j]&&grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,visited,i,j,m,n,-1,-1);
                }
            }
        }
        return count;
    }
};


// Without parent
class Solution {
public:
    bool isValid(int i,int j,int m,int n)
    {
        if(i<0||j<0||i>=m||j>=n)return false;
        return true;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>&visited,int i,int j,int m,int n)
    {
        if(visited[i][j])return;
        visited[i][j]=true;
        if(isValid(i-1,j,m,n)&&grid[i-1][j]=='1') dfs(grid,visited,i-1,j,m,n);
        if(isValid(i+1,j,m,n)&&grid[i+1][j]=='1') dfs(grid,visited,i+1,j,m,n);
        if(isValid(i,j-1,m,n)&&grid[i][j-1]=='1') dfs(grid,visited,i,j-1,m,n);
        if(isValid(i,j+1,m,n)&&grid[i][j+1]=='1') dfs(grid,visited,i,j+1,m,n);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j]&&grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,visited,i,j,m,n);
                }
            }
        }
        return count;
    }
};


