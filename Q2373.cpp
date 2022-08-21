class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vec(n-2,vector<int>(n-2));
        int x=n-2;
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                int maxi=0;
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        maxi=max(maxi,grid[i+k][j+l]);
                    }
                }
                vec[i][j]=maxi;
            }
        }
        return vec;
    }
};
