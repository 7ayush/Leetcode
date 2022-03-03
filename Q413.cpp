class Solution {
public:
    int util(int i)
    {
        return (i)*(i-1)/2;
    }
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int ans=0;
        vector<int>diff(nums.size());
        diff[0]=0;
        for(int i=1;i<nums.size();i++)
        {
            diff[i]=nums[i]-nums[i-1];
        }
        for(int i=1;i<nums.size()-1;i++)
        {
            int count=1;
            while(i+1<nums.size()&&diff[i+1]==diff[i])
            {
                count++;
                i++;
            }
            ans+=util(count);
        }
        return ans;
        
    }
};

