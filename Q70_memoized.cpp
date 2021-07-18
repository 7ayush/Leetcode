// Recursion with memoization to overcome repeating calls

class Solution {
public:
    int climbRecursive(int i,int n,int *arr)
    {
        if(i>n)  return 0;
        if(i==n) return 1;        
        
        if(arr[i]>=0)return arr[i];
        arr[i]=climbRecursive(i+1,n,arr)+climbRecursive(i+2,n,arr);
        return arr[i];
    }
    int climbStairs(int n) {
        int *arr=new int[n+1];
        memset(arr,-1,(n+1)*sizeof(int));
        return climbRecursive(0,n,arr);
    }
};
