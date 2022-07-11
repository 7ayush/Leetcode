class Solution {
public:
    int util(vector<int>& arr,vector<int>& dp, int i,int d) 
    {
        int n=arr.size();
        if(dp[i]!=-1)return dp[i];
        int ans=1;
        for(int j=i+1;j<=min(i+d,n-1)&&arr[i]>arr[j];j++)
        {
            ans=max(ans,1+util(arr,dp,j,d));
        }
        for(int j=i-1;j>=max(i-d,0)&&arr[i]>arr[j];j--)
        {
            ans=max(ans,1+util(arr,dp,j,d));
        }
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        vector<int>dp(arr.size(),-1);
        int ans=1;
        for(int i=0;i<arr.size();i++)
        {
            ans=max(ans,util(arr,dp,i,d));
        }
        return ans;
    }
};
