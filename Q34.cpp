class Solution {
public:
    int first(vector<int>&nums,int target)
    {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                 if(mid-1>=start&&nums[mid-1]==target)end=mid-1;
                 else return mid;                
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return -1;
    }
    int second(vector<int>&nums,int target)
    {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                 if(mid+1<=end&&nums[mid+1]==target)start=mid+1;
                 else return mid;                
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),second(nums,target)};
    }
};
