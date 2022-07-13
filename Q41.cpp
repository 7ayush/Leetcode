// Method 1 Sorting 
// Method 2 Hashmap
// Observation our answer will lie between 1 to len(nums)+1
// Since we do not want to take extra space we will use our array as hashmap. we will map index i with i+1.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mini=1;
        int maxi=nums.size()+1;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>=mini&&nums[i]<maxi&&nums[i]!=i+1&&nums[i]!=nums[nums[i]-1]) 
            //checking if the value lies in range and if values are needed to be swapped and if 2 swapped values are unequal
            {                
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)return i+1;
        }
        return maxi;
    }
}; 
