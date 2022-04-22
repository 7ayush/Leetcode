class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int x=log2(n);
        x=pow(2,x+1)-1;
        return x^n;
    }
};
