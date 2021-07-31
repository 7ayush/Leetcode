class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>dp;
        vector<int>r1;
        r1.push_back(1);
        dp.push_back(r1);
        for(int i=1;i<numRows;i++)//i=2 
        {
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i;j++) //1
            {
                temp.push_back(dp[i-1][j-1]+dp[i-1][j]);
            }
            temp.push_back(1);
            dp.push_back(temp);
        }
        return dp;
        
    }
};
