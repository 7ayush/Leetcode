// O(log2(n)) time O(1) space
// Iterative solution
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n<1)return 0;
        if(n==1)return 1;
        while(n>1)
        {
            if(n%2!=0)return 0;
            n=n/2;
        }
        return 1;
    }
};
