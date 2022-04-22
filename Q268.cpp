class Solution {
public:
    int computeXOR(int n)
    {
      if (n % 4 == 0) return n;
      if (n % 4 == 1) return 1;
      if (n % 4 == 2) return n + 1;
      return 0;
    }

    int missingNumber(vector<int>& nums) {
        int n=computeXOR(nums.size());
        for(int i:nums)n=n^i;
        return n;
    }
};
