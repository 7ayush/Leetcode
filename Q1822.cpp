class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countMinus=0;
        for(auto i:nums)
        {
            if(i==0)return 0;
            else if(i<0)countMinus++;

        }
        if(countMinus&1)return -1;
        return 1;
    }
};
