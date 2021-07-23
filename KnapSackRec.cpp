// { Driver Code Starts
#include "bits.h"
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSackUtil(int w,int wt[],int val[],int n,int **dp)
    {
        if(n==0||w==0) return 0;
        
        if(dp[n][w]!=-1)return dp[n][w];
        
        if(w>=wt[n-1])
        {
            dp[n][w]=max(val[n-1]+knapSackUtil(w-wt[n-1],wt,val,n-1,dp),knapSackUtil(w,wt,val,n-1,dp));
        }
        else
        {
            dp[n][w]=knapSackUtil(w,wt,val,n-1,dp);
        }
        return dp[n][w];
        
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       int **dp=new int*[n+1];
       for(int i=0;i<n+1;i++)
       {
           dp[i]=new int[w+1];
       }
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<w+1;j++)
           {
               dp[i][j]=-1;   
           }
       }
       knapSackUtil(w,wt,val,n,dp);
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends