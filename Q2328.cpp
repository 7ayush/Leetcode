//DFS + memoization
class Solution {
public:
    bool isValid(int i,int j,int m,int n)
    {
        if(i<0||j<0||i>=m||j>=n)return false;
        return true;
    }
    int dfs(vector<vector<int>>&visited,vector<vector<int>>&count,vector<vector<int>>&grid,int i,int j,int m,int n)
    {
        if(visited[i][j])return count[i][j];
        visited[i][j]=true;
        int mod=1e9+7;
        if(isValid(i+1,j,m,n)&&grid[i+1][j]>grid[i][j])     count[i][j]=(count[i][j]+dfs(visited,count,grid,i+1,j,m,n))%mod;
        if(isValid(i-1,j,m,n)&&grid[i-1][j]>grid[i][j])     count[i][j]=(count[i][j]+dfs(visited,count,grid,i-1,j,m,n))%mod;
        if(isValid(i,j+1,m,n)&&grid[i][j+1]>grid[i][j])     count[i][j]=(count[i][j]+dfs(visited,count,grid,i,j+1,m,n))%mod;
        if(isValid(i,j-1,m,n)&&grid[i][j-1]>grid[i][j])     count[i][j]=(count[i][j]+dfs(visited,count,grid,i,j-1,m,n))%mod;
        return count[i][j];
 
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>count(m,vector<int>(n,1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j])
                    dfs(visited,count,grid,i,j,m,n);
            }   
        }
        
        long long c=0;
        int mod=1e9+7;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                c=(c+count[i][j])%mod;
            }   
        }
        return c;
    }
};
