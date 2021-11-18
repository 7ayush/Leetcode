// In this question we are making a dp matrix of m*n
// filling the first row and first column with 1 and then the number of ways to reach any cell is sum of value in one above and one left cell
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }   
        }
        return dp[m-1][n-1];
    }
};
//This is a recursive implement of the code but it is giving TLE. 
class Solution {
public:
    void util(int i,int j,int m,int n,int *count)
    {
        if(i>=m&&j>=n)return;
        if(i<m&&j<n)
        {
            *count=*count+1;
            util(i+1,j,m,n,count);
            util(i,j+1,m,n,count);
        }
        else if(i<m)
        {
            util(i+1,j,m,n,count);
        }
        else if(j<n)
        {
            util(i,j+1,m,n,count);
        }
    }
    int uniquePaths(int m, int n) {
        int count=1;        
        util(1,1,m,n,&count);
        return count;
    }
};
