//BFS Solution
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();        
        int n=mat[0].size();
        if(m==0||n==0)return mat;
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }   
        }
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            // cout<<it.first<<" "<<it.second<<endl;
            for(int i=0;i<4;i++)
            {
                int nr=it.first+dir[i][0];
                int nc=it.second+dir[i][1];
                if(nr<0||nc<0||nr>=m||nc>=n)continue;
                if(dp[nr][nc]>dp[it.first][it.second]+1)
                {
                    dp[nr][nc]=dp[it.first][it.second]+1;
                    q.push({nr,nc});
                }                
            }
           
        }
        return dp;
    }
};

// Dynamic Programming 
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();        
        int n=mat[0].size();
        if(m==0||n==0)return mat;
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX-100000));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                    continue;
                }                
                if (i > 0)
                    dp[i][j] =min(dp[i][j],dp[i-1][j]+1);
                if (j > 0)
                    dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {               
                if (i<m-1)
                    dp[i][j] =min(dp[i][j],dp[i+1][j]+1);
                if (j < n-1)
                    dp[i][j] = min(dp[i][j],dp[i][j+1]+1);
            }
        }      
        return dp;
    }
};
