class Solution {
public:
    int findComplement(int num) {
        int x=log2(num);
        x=pow(2,x+1)-1;
        return x^num;
    }
};
