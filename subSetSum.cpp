// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool isSubsetUtil(int n,int arr[],int sum,int **dp)
    {
        if(sum==0) return true;
        if(n==0) return false;
        
        if(dp[n][sum]!=-1)return dp[n][sum];
        
        if(arr[n-1]<=sum)
        {
            dp[n][sum]=isSubsetUtil(n-1,arr,sum,dp)||isSubsetUtil(n-1,arr,sum-arr[n-1],dp);
        }
        else
        {
            dp[n][sum]=isSubsetUtil(n-1,arr,sum,dp);
        }
        return dp[n][sum];
    }
    bool isSubsetSum(int n, int arr[], int sum)
    {
        // code here
        int **dp=new int*[n+1];
        
        for(int i=0;i<n+1;i++)
        {
            dp[i]=new int[sum+1]();
        }
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                dp[i][j]=-1;
            }
        
        }
        return isSubsetUtil(n,arr,sum,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
