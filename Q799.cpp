class Solution {
public:
    double champagneTower(int poured, int rows, int glass) 
    {
        vector<vector<double>>dp;
        for(int i=0;i<100;i++)
        {
            vector<double>temp(i+1,0.00000);
            dp.push_back(temp);
        }
        dp[0][0]=(double)poured;
        for(int i=0;i<=rows;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(i+1<100&&dp[i][j]>1)
                {
                    double x=dp[i][j]-1;
                    dp[i][j]=1;
                    dp[i+1][j]+=x/2;
                    dp[i+1][j+1]+=x/2;
                }
            }   
        }
        return dp[rows][glass]>1?1:dp[rows][glass];
    }
};
