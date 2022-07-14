// Two pointer
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0;
        int len=nums.size()+1;
        int sum=0;
        int n=nums.size();
        while(r<n)
        {
            sum+=nums[r];
            while(sum>target)
            {
                len=min(len,r-l+1);
                if(l==r)
                {
                    sum=0;
                    r++;
                    l=r;
                }                
                sum-=nums[l++];
            }            
            if(sum==target)len=min(len,r-l+1);
            r++;
        }
        return len==nums.size()+1?0:len;
    }
};
