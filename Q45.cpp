class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach=0;
        int current=0;
        int jumps=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            maxReach=max(maxReach,i+nums[i]);
            if(current==i)
            {
                jumps++;
                current=maxReach;
            }            
        }
        return jumps;
    }
};
