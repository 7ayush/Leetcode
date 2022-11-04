class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            int x=matrix[i][0];
            int j=0;
            int k=i;
            while(k<matrix.size()&&j<matrix[0].size())
            {
                if(matrix[k][j]!=x)return false;
                k++;j++;
            }
        }
        for(int j=1;j<matrix[0].size();j++)
        {
            int x=matrix[0][j];
            int i=0;
            int k=j;
            while(k<matrix[0].size()&&i<matrix.size())
            {
                if(matrix[i][k]!=x)return false;
                k++;i++;
            }
        }
        return true;
    }
};
