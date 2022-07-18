class Solution {
public:
    double util(int i,int j,int n,int k,vector<vector<vector<double>>>&dp)
    {
        if(i<0||j<0||i>=n||j>=n)return 0; 
        if(k==0)return 1;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        double sum= util(i+1,j+2,n,k-1,dp)+ 
                    util(i+2,j+1,n,k-1,dp)+ 
                    util(i+2,j-1,n,k-1,dp)+ 
                    util(i+1,j-2,n,k-1,dp)+ 
                    util(i-1,j-2,n,k-1,dp)+ 
                    util(i-2,j-1,n,k-1,dp)+ 
                    util(i-2,j+1,n,k-1,dp)+ 
                    util(i-1,j+2,n,k-1,dp); 
         sum=sum/8;   
        
        return dp[i][j][k]=sum;
                    
    }
        
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>> (n + 1, vector<double>(k + 1, -1)));
        int count=0;
        int totalCount=0;
        return util(row,column,n,k,dp);
    }
};
