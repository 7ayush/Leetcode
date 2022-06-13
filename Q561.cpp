// Since we have to maximize the minimum we want that 2 smallest elements remaining should be combined
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i+=2)
        {
            sum+=min(nums[i],nums[i+1]);
            
        }
        return sum;
    }
};
