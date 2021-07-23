class Solution {
public:
    int rec(int *arr,int n)
    {
        if(arr[n]!=-1)return arr[n];
        arr[n]=rec(arr,n-1)+rec(arr,n-2);
        return arr[n];
    }
    int fib(int n) 
    {
        if(n<=1)return n;
        int *arr=new int[n+1];
        memset(arr,-1,sizeof(int)*(n+1));
        arr[0]=0;
        arr[1]=1;        
        return rec(arr,n);
    }
};
