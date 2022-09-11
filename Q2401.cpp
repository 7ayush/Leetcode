//Sliding Window
class Solution {
public:
    bool check(vector<int>&nums)
    {
        for(int i=0;i<32;i++)
        {
            if(nums[i]>1)return false;
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        vector<int>bits(32,0);
        int ans=1;
        while(j<n)
        {
            int x=nums[j];
            int idx=0;
            while(x>0)
            {
                bits[idx]+=x%2;
                x=x>>1;
                idx++;
            }
            while(!check(bits)&&i<j)
            {
                int x=nums[i];
                int idx=0;
                while(x>0)
                {
                    bits[idx++]-=x%2;
                    x=x>>1;
                }   
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
                
        }
        return ans;
    }
};
