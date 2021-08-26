class Solution {
public:
    int search(int l,int r,vector<int>nums)
    {
        if(l==r)return l;
        int mid=(l+r)/2;
        if(nums[mid]>nums[mid+1])return search(l,mid,nums);
        else return search(mid+1,r,nums);
    }
    int findPeakElement(vector<int>& nums) 
    {
        return search(0,nums.size()-1,nums);
    }
};
