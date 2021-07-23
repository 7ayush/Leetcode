// { Driver Code Starts
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1# 
// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    bool util(int arr[],int n,int sum,vector<vector<int>>&dp)
    {
        if(sum==0) return dp[n][sum]=1;
        
        if(n==0) return dp[n][sum]=0;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        else
        {
            if(arr[n-1]<=sum)
            {
                return dp[n][sum]=util(arr,n-1,sum-arr[n-1],dp)||util(arr,n-1,sum,dp);
            }
            else
            {
                return dp[n][sum]=util(arr,n-1,sum,dp);
            }
        }
    }
	int minDifference(int arr[], int n)  
	{ 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)sum+=arr[i];
	    int half=sum/2;
	    vector<vector<int>> dp(n+1, vector<int> (half+1, -1));
	    int min=sum;
	    for(int i=0;i<=half;i++)
	    {
	        util(arr,n,i,dp);    
	    }
	    for(int i=0;i<=half;i++)
	    {
	        if(dp[n][i]==1)
	        {
	            if(min>=abs(sum-2*i)) 
	            {
	                min=abs(sum-2*i);
	            }
	        }
	    }
	    return min;
	 
	} 
};

 // for(int i=0;i<n+1;i++)
	   // {
	   //     for(int j=0;j<half+1;j++)
    // 	    {
    // 	        cout<<dp[i][j]<<" ";
    // 	    }   
    // 	    cout<<endl;
	   // } 
// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
