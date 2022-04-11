// Bruteforce solution 
class Solution {
public:
    void shiftOnce(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>last(m);
        
        for(int i=0;i<m;i++)
        {
            last[i]=grid[i][n-1];
        }
        for(int j=n-1;j>0;j--)
        {
            for(int i=0;i<m;i++)
            {
                grid[i][j]=grid[i][j-1];
            }
        }
        grid[0][0]=last[m-1];
        for(int i=0;i<m-1;i++)
        {
            grid[i+1][0]=last[i];
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        while(k--)
        {
            shiftOnce(grid);
        }
        return grid;
    }
};


// Finding out the new coordinates and then updating the value at that index
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=(i+(j+k)/n)%m;
                int y=(j+k)%n;
                ans[x][y]=grid[i][j];
            }   
        }
        return ans;
    }
};
