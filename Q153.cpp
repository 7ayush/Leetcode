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
    int findMin(vector<int>& nums) 
    {
        int pivot=findPivot(nums,0,nums.size()-1);
        if(nums.size()==1)return nums[0];
        if(pivot==-1||pivot==nums.size()-1)return nums[0];
        return min(nums[0],nums[pivot+1]);
        
    }
};
