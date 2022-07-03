// Time O(nlogn) space depends on sorting algorithm
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]==nums[i])
            {
                return nums[i];
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int>s;
        for(int i:nums)
        {
            if(s.find(i)!=s.end())
            {
                return i;
            }
            else
            {
                s.insert(i);
            }
        }
        return -1;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& arr) 
    {
        for(int i=0;i<arr.size();i++)
        {
            int x=abs(arr[i]);
            if(arr[x]<0)
            {
                return x;
            }
            else
            {
                arr[x]*=-1;
            }
        }
        return -1;
    }
};

