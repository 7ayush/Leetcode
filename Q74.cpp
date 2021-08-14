// Bruteforce solution O(m*n)
class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)    
        {
            for(int j=0;j<matrix[0].size();j++)    
            {
                if(matrix[i][j]==target)return true;
            }   
        }
        return false;
    }
};



// Average Solution
// try binary search on every row if element is found then return true else return false
class Solution {
public:
    bool binarySearch(vector<int>vec,int i,int j,int target)
    {
        if(i>j)return false;
        int mid=(i+j)/2;
        if(vec[mid]==target)return true;
        else if(vec[mid]>target)return binarySearch(vec,i,mid-1,target);
        else return binarySearch(vec,mid+1,j,target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i=0;i<matrix.size();i++)
        {
            if(binarySearch(matrix[i],0,matrix[i].size()-1,target))return true;
        }
        return false;
    }
};

// Optimal solution
// You will initialise i=0 and j=columns-1 if matrix[i][j]=target return true;
// If matrix[i][j]<target this means the target element is below the current element
// If matrix[i][j]>target this means the target element lies to the left of current element
class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;     
        while(i<matrix.size()&&j>=0)
        {
            if(matrix[i][j]==target)return true;
            else if(matrix[i][j]>target)j--;
            else i++;
        }
        return false;
    }
};
