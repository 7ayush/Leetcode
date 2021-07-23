// Bruteforce method without any memoization
// Time-> O(2^n) 
// Space-> O(n) height of recursion tree
class Solution {
public:
    int climbRecursive(int i,int n)
    {
        if(i>n)  return 0;
        if(i==n) return 1;
        return climbRecursive(i+1,n)+climbRecursive(i+2,n);
    }
    int climbStairs(int n) {
        return climbRecursive(0,n);
    }
};
