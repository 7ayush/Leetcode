// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int binarySearch(int l,int r)
    {        
        if(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isBadVersion(mid)==true&&(mid==1||isBadVersion(mid-1)==false))
            {
                return mid;
            }
            else if(isBadVersion(mid)==false)
            {
                return binarySearch(mid+1,r);
            }
            else
            {
                return binarySearch(l,mid-1);
            }
        }
        return -1;
    }
    int firstBadVersion(int n) {
        return binarySearch(1,n);
    }
};
