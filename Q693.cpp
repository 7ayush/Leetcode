class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int>nums;
        while(n>0)
        {
            nums.push_back(n&1);
            n=n>>1;
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])return false;
        }
        return true;
    }
};
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cur = n & 1;
        n=n>>1;
        while (n > 0) {
            if (cur == n &1) return false;
            cur = n & 1;
            n =n>>1;
        }
        return true;
    }
};
