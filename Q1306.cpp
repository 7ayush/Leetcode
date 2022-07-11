class Solution {
public:
    bool util(vector<int>& arr, int start,vector<int>&dp,vector<int>&visited)
    {
        if(start<0||start>=dp.size())return false;
        if(arr[start]==0)return dp[start]=true;
        if(visited[start])return dp[start];
        visited[start]=1;
        bool choice1=util(arr,start-arr[start],dp,visited);
        bool choice2=util(arr,start+arr[start],dp,visited);
        
        return dp[start]=choice1||choice2;
        
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>dp(arr.size(),0);
        vector<int>visited(arr.size(),0);
        return util(arr,start,dp,visited);        
    }
};
