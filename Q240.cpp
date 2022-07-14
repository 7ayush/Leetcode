class Solution {
public:
    bool binarySearch(vector<int>&vec,int i,int j,int target)
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

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up=0;
        int left=0;
        int down=matrix.size()-1;
        int right=matrix[0].size()-1;        
        while(up<=down&&left<=right)
        {
            if(matrix[up][right]==target||matrix[down][left]==target)return true;
            if(matrix[up][right]<target){
                up++;
            }
            else
            {
                right--;
            }
            if(matrix[down][left]<target){
                left++;
            }
            else
            {
                down--;
            }
        }
        return false;
    }
};
