class Solution {
public:
    int helper(vector<int>& nums,int i,int j){
        if(i >= j) return nums[i];
        int mid = i+(j-i)/2;
        if(nums[mid] > nums[0])
            return helper(nums,mid+1,j);
        else if(nums[mid] == nums[0]){
            return min(helper(nums,i,mid-1),helper(nums,mid+1,j));
        }
        else
            return min(nums[mid],helper(nums,i,mid-1));
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n-1])
            return nums[0];
        int i = 0,j = n-1;
        return helper(nums,i,j);
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]) low=mid+1;
            else if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;  high--;
            }
            else high=mid;
        }
        return  nums[low];
    }
};
