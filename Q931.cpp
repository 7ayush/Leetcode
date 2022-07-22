class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size()==1)return *min_element(matrix[0].begin(),matrix[0].end());
        for(int i=matrix.size()-2;i>=0;i--)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                int left=INT_MAX,right=INT_MAX,down=matrix[i+1][j];
                if(j!=0)left=matrix[i+1][j-1];
                if(j!=matrix[i].size()-1)right=matrix[i+1][j+1];
                matrix[i][j]+=min(left,min(right,down));
            }
        }
        return *min_element(matrix[0].begin(),matrix[0].end());
    }
};
