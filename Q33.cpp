class Solution {
public:
    int findPivot(vector<int>arr,int l,int r)
    {
        if(l<=r)
        {
            int mid=(l+r)/2;
            if(l==r)return r;
            if(mid<r&&arr[mid]>arr[mid+1])return mid;
            if(mid>l&&arr[mid]<arr[mid-1])return mid-1;
            if(arr[l]>=arr[mid])return findPivot(arr,l,mid-1);      
            return findPivot(arr,mid+1,r);            
        }
        return -1;
    }
    int binarySearch(vector<int>arr,int l,int r,int x)
    {
        if(l<=r)
        {
            int mid=(l+r)/2;
            if(arr[mid]==x)return mid;
            else if(arr[mid]<x)return binarySearch(arr,mid+1,r,x);
            return binarySearch(arr,l,mid-1,x);            
        }
        return -1;
    }
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int pivot=findPivot(nums,0,n-1);
        if(pivot==-1)return binarySearch(nums,0,n-1,target);
        if(nums[pivot]==target)
        {
            return pivot;
        }
        else
        {
            int left=binarySearch(nums,0,pivot-1,target);
            int right=binarySearch(nums,pivot+1,nums.size()-1,target);
            if(left==-1&&right==-1)return -1;
            return left!=-1?left:right;
        }
    }
};
