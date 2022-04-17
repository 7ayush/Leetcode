class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> min_heap;       
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(i>0 && j>0) matrix[i][j]= (matrix[i-1][j]^matrix[i][j-1])^matrix[i][j]^matrix[i-1][j-1];
                else if(i>0 && j<=0) matrix[i][j]=matrix[i-1][j]^matrix[i][j];
                else if(i<=0 && j>0) matrix[i][j]=matrix[i][j-1]^matrix[i][j];
              
                min_heap.push(matrix[i][j]);
                
                if(min_heap.size()>k)
                        min_heap.pop();
            }
        }
        
    
        return min_heap.top();
    }
};
