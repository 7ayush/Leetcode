class Solution {
public:
    vector<int> findErrorNums(vector<int>nums) {
        int xor_val=0;
        for(int i=0;i<nums.size();i++)
        {
            xor_val=xor_val^nums[i];
        }

        for(int i=1;i<=nums.size();i++)
        {
            xor_val=xor_val^i;
        }

        int righmostsetbit=xor_val & ~(xor_val-1);
        cout<<righmostsetbit;
        int xor_group0=0,xor_group1=0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i] & righmostsetbit)==0)
            {
                xor_group0^=nums[i];
            }
            else
            {
                xor_group1^=nums[i];
            }
        }

        for(int i=1;i<=nums.size();i++)
        {
            if((i & righmostsetbit)==0)
            {
                xor_group0^=i;
            }
            else
            {
                xor_group1^=i;
            }
        }

        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==xor_group1)
            {
                res.push_back(xor_group1);
                res.push_back(xor_group0);
                return res;
            }
        }

        res.push_back(xor_group0);
        res.push_back(xor_group1);
        return res;
    }
};
