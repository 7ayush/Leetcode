// Binary Search Solution
class Solution {
public:
        int searchInsert(vector<int>& nums, int target) 
        {
            int left = 0;
            int right = nums.size();
            while(left < right){
                int mid = left + (right-left)/2;
                if(nums[mid] >= target) right = mid;
                else left = mid+1;
            }
            return left;
        }
};


// You can also use upper_bound for this
// Lower bound function means index of first equal to or greater than
// Upper bound function means index of first greater than or last equal to
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        vector<int>::iterator it=find(nums.begin(),nums.end(),target);
        if(it!=nums.end())
        {
            return (it-nums.begin());
        }
        else
        {
            it=lower_bound(nums.begin(),nums.end(),target);
            return it-nums.begin();
        }
    }
};
