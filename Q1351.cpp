// Using binary search to find the index of first negative number in the list and then calculating the number of negative numbers from the no of columns
class Solution {
public:
    int binarySearch(vector<int>arr)
    {
        int start=0;
        int end=arr.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]<0)
            {
                if(mid-1<0||arr[mid-1]>=0)return mid;
                else
                {
                    end=mid-1;
                }
            }
            else
            {
                start=mid+1;
            }
        }
        return -1;
        
    }
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            int x=binarySearch(grid[i]);
            if(x==-1)continue;
            else count+=c-x;
            
        }
        return count;
        
        
    }
};
