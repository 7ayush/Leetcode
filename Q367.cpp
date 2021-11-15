class Solution {
public:
    bool isPerfectSquare(int n) {
        long lo = 1, hi = n;
        while (lo <= hi) {
            long mid = (lo+hi)/2;
            long total = mid*mid;
            if (total == n) {
                return true;
            }
            else if (total > n) {
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return false;
    }
};
