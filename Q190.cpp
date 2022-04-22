class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int>vec(32,0);
        int i=0;
        while(n>0)
        {
            vec[i]=n&1;
            n=n>>1;
            i++;
        }
        uint32_t ans=0;
        for(int i=0;i<32;i++)
        {
            ans=2*ans+vec[i];
        }
        return ans;
    }
};
