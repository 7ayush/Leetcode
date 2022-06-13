class Solution {
public:
    bool isValid(int i,int j)
    {
        if(j<0||j>i)return false;
        return true;
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int ans=INT_MAX;
        if(triangle.size()==1)return triangle[0][0];
        for(int i=1;i<triangle.size();i++)
        {
              for(int j=0;j<=i;j++)
              {
                  int top= !isValid(i-1,j) ? INT_MAX : triangle[i-1][j];
                  int topLeft= !isValid(i-1,j-1)? INT_MAX:triangle[i-1][j-1];
                  triangle[i][j]+=min(top,topLeft);
                  if(i==triangle.size()-1){
                      ans=min(ans,triangle[i][j]);
                  }
              }
        }
        return ans;
    }
};
