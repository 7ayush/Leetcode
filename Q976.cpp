class Solution {
public:
    bool sum(int a,int b,int c)
    {
        if(b+c<=a)return false;
        return true;
    }
    bool diff(int a,int b,int c)
    {
        if(a-b>=c)return false;
        if(a-c>=b)return false;
        return true;
    }
    int largestPerimeter(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(sum(nums[i],nums[i+1],nums[i+2])&&diff(nums[i],nums[i+1],nums[i+2]))
                return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};
