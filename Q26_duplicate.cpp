class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0,j=0;
        while(j<nums.size())
        {
            while(j<nums.size()&&nums[j]==nums[i])
            {
                j++;
            }
            i++;
            if(nums[i-1]==nums[j-1]&&j<nums.size())
            {
                cout<<i<<" "<<j<<endl;
                nums[i]=nums[j];
            }
        }
        // cout<<i+1<<" "<<endl;
        // nums.erase(nums.begin()+i+1,nums.end());
        return i;
    }
};
