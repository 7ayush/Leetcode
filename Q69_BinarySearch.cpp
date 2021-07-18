class Solution {
public:
    int mySqrt(int x) 
    {
        if(x<=1)return x;
        
        int low=0,high=x;
        long long int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(mid*mid==x)return mid;
            else if(mid*mid<x)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low-1;
    }
};
