class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left=0,right=n-1,up=0,down=m-1;
        vector<int> v;
        int total=n*m,i=0;
        while(i<total){

            //StartRow
            for(int j=left;j<=right&&i<total;j++){
                v.push_back(matrix[up][j]);                  
                i++;
            } 
            up++;
            for(int j=up;j<=down&&i<total;j++){
                v.push_back(matrix[j][right]);                  
                i++;
            } 
            right--;
            //EndCol
            for(int j=right;j>=left&&i<total;j--){
                v.push_back(matrix[down][j]);                  
                i++;
            } 
            down--;
            for(int j=down;j>=up&&i<total;j--){
                v.push_back(matrix[j][left]);                  
                i++;
            } 
            left++;
            
            //EndRow
            
	}
        return v;
    }
};
