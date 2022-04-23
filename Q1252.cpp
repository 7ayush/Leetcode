class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>>vec(m,vector<int>(n,0));
        for(auto i:indices)
        {
            int r=i[0];
            int c=i[1];
            for(int i=0;i<n;i++)
            {
                vec[r][i]++;
            }
            for(int i=0;i<m;i++)
            {
                vec[i][c]++;
            }
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vec[i][j]&1)count++;
            }   
        }
        return count;
    }
};
