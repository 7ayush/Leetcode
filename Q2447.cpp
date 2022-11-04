class Solution {
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);   
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int temp=nums[i];
            if(temp==k)ans++;
            for(int j=i+1;j<n;j++)
            {
                temp=gcd(temp,nums[j]);
                if(temp==k)ans++;
            }
        }
        return ans;
    }
};
