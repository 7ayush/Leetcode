class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        if(i<0||j<0||i>=n||j>=m)return false;
        return true;
    }
    bool dfs(vector<vector<char>>& grid,vector<vector<bool>>&visited,int i,int j,int pi,int pj)
    {              
        int n=grid.size();
        int m=grid[0].size();
        if(visited[i][j])return true;
        visited[i][j]=true;
        bool up=false;        
        bool down=false,left=false,right=false;
        if(isValid(i-1,j,n,m)&&grid[i-1][j]==grid[i][j])
        {
            if(i-1!=pi||j!=pj)
            {
                up=dfs(grid,visited,i-1,j,i,j);    
            }
        }
        if(isValid(i+1,j,n,m)&&grid[i+1][j]==grid[i][j])
        {
            if(i+1!=pi||j!=pj)
            {
                down=dfs(grid,visited,i+1,j,i,j);    
            }
        }
        if(isValid(i,j-1,n,m)&&grid[i][j-1]==grid[i][j])
        {
            if(i!=pi||j-1!=pj)
            {
                left=dfs(grid,visited,i,j-1,i,j);    
            }
        }
        if(isValid(i,j+1,n,m)&&grid[i][j+1]==grid[i][j])
        {
            if(i!=pi||j+1!=pj)
            {
                left=dfs(grid,visited,i,j+1,i,j);    
            }
        }
        return up||down||left||right;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j]&&dfs(grid,visited,i,j,-1,-1))return true;
            }
        }
        return false;
    }
    
};
