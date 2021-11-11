class Solution {
public:
    static int binarySearch(vector<int>arr,int start,int end)
    {
        if(start<end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]<arr[mid+1])
            {
                return binarySearch(arr,mid+1,end);
                
            }
            else
            {
                return binarySearch(arr,start,mid);
            }            
        }
        return start;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size()-1;
        return binarySearch(arr,0,n-1);
        
    }
};