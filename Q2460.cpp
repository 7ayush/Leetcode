class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
                i++;
            }
        }
        vector<int>temp;
        for(auto i:nums)
        {
            if(i!=0)temp.push_back(i);
        }
        int i=0;
        for(;i<temp.size();i++)
        {
            nums[i]=temp[i];
        }
        for(;i<nums.size();i++)nums[i]=0;
        return nums;
    }
};

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
                i++;
            }
        }
        int p=-1,i=0;
        while(i<nums.size())
        {
            if(nums[i]!=0)
            {
                p++;
                if(i!=p)
                {
                    swap(nums[i],nums[p]);
                }
            }
            i++;
        }
        return nums;
    }
};
