//BFS Solution
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>>matrix(m,vector<int>(n,0));
        int ans=0;
        int mod=1e9+7;
        queue<pair<int,int>>q;
        q.push({startRow,startColumn});
        matrix[startRow][startColumn]=1;
        for(int i=0;i<maxMove;i++)
        {
            int a=q.size();
            while(a--)
            {
                auto [x,y]=q.front();
                q.pop();
                if(matrix[x][y]==0)continue;
                vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
                for(auto it:dir)
                {
                    int nx=x+it[0];
                    int ny=y+it[1];
                    if(nx<0||nx==m||ny<0||ny==n)ans=(ans+matrix[x][y])%mod;
                    else{
                        matrix[nx][ny]=(matrix[nx][ny]+matrix[x][y])%mod;
                        q.push({nx,ny});
                    } 
                }
                matrix[x][y]=0;
            }
        }
        return ans;
        
        
    }
};



// Time Complexity O(m*n*maxMove)
class Solution {
public:    
    long findPathsMemoHelper(int m, int n, int maxMove, int row, int col,vector<vector<vector<int>>>&dp) 
    {
        int mod = 1000000007;
        if (maxMove < 0) return 0;
    
        if (row == m || col == n || row < 0 || col <0)return 1; // boundary condition
        if (dp[row][col][maxMove] != -1)return dp[row][col][maxMove];

        long total = 0;
        long left_maxMoveReduced  = findPathsMemoHelper(m, n, maxMove - 1, row, col - 1,dp);
        long right_maxMoveReduced = findPathsMemoHelper(m, n, maxMove - 1, row, col + 1,dp);
        long up_maxMoveReduced    = findPathsMemoHelper(m, n, maxMove - 1, row - 1, col,dp);
        long down_maxMoveReduced  = findPathsMemoHelper(m, n, maxMove - 1, row + 1, col,dp);

        total =  (( left_maxMoveReduced + right_maxMoveReduced + down_maxMoveReduced + up_maxMoveReduced) % mod);
        
        return dp[row][col][maxMove] = total;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return (int)(findPathsMemoHelper(m, n, maxMove, startRow, startColumn,dp));    
    }
};
