class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>mat(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')count++;
                else count=0;
                mat[i][j]=count;    
            }   
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int curr=INT_MAX;
                int count=0;
                for(int k=0;k<min(curr,i+1);k++)
                {
                    if(mat[i-k][j]<k+1) break;                    
                    else count++;
                    curr=min(curr,mat[i-k][j]);
                }
                ans=max(ans,count);
            }                
        }
        return ans*ans;
    }
};


// For having size of 3 square at a pt the above point, point to the diagonal left,point to diagonal right should be the bottom right point of square of size 2
/*
1 1 1   is only possible when  0 0  0       (1 1) 1           (1 1) 
1 1 1                         (1 1) 1 and   (1 1) 1   and   0 (1 1)
1 1 1                         (1 1) 1        0 0  1         0  0 1  simuntaneously
*/



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};
