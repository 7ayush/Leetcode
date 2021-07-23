// O(log2(n)) time O(1) space
// Bit Manipulation solution
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        int count=0;
        if(n<1)return 0;
        while(n>0)
        {
            count+=n%2?1:0;
            n=n/2;
        }
        if(count==1)return 1;
        return 0;
    }
};
