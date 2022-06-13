class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>mat1(r,vector<int>(c,0));
        int m=mat.size(),n=mat[0].size();
        int p=0,q=0;
        if(c!=m*n/r)return mat;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat1[p][q]=mat[i][j];
                q++;
                if(q==c)
                {
                    q=0;
                    p++;
                }
            }   
        }
        return mat1;
    }
};
