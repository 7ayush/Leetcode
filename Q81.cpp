class Solution {
public:

    bool search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int start=0,end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)return true; //found

            bool same=nums[start]==nums[mid]; 
            //if same then              
            if(same){
                start=start+1; 
                continue;
            }
            bool pivotArray=nums[start]<=nums[mid];
            bool targetArray=nums[start]<=target;
            if(pivotArray^targetArray)
            {
                if(pivotArray)start=mid+1; //
                else end=mid-1;
            }
            else 
                if(nums[mid]<=target)start=mid+1;
                else end=mid-1;
        }
        
        return false;
    }
};
