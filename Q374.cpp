/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1,u=n;
        while(l<=u)
        {
            int mid=l+(u-l)/2;
            int x=guess(mid);
            if(x==0)
                return mid;
            else if(x==1)
                l=mid+1;
            else
                u=mid-1;
        }
        return -1;
    }
};
