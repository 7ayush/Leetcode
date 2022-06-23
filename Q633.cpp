//Two Pointers 
class Solution {
public:
    bool judgeSquareSum(int c) {
        long int i=0;
        long int j=sqrt(c);
        while(i<=j)
        {
            long long ans=i*i+j*j;
            if(ans==c)return true;
            else if(ans<c)i++;
            else j--;
        }
        return false;
    }
};

//Binary Search
class Solution {
public:
    bool binary_search(long s, long e, int n) {
        if (s > e)
            return false;
        long mid = s + (e - s) / 2;
        if (mid * mid == n)
            return true;
        if (mid * mid > n)
            return binary_search(s, mid - 1, n);
        return binary_search(mid + 1, e, n);
    }
    bool judgeSquareSum(int c) 
    {
        for (long a = 0; a * a <= c; a++) {
            int b = c - (int)(a * a);
            if (binary_search(0, b, b))
                return true;
        }
        return false;
    }
};
