//Recursive Solution
class Solution {
public:
    int util(vector<int>& nums, vector<int>& multipliers,int i,int j,int k)
    {
        if(i>j||k>=multipliers.size())return 0;
        return max(multipliers[k]*nums[i]+util(nums,multipliers,i+1,j,k+1),multipliers[k]*nums[j]+util(nums,multipliers,i,j-1,k+1));
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int m=nums.size();
        return util(nums,multipliers,0,m-1,0);        
    }
};

//Memoized
class Solution {
public:
    bool vis[1001][1001];
    int util(vector<int>& nums, vector<int>& multipliers,int i,int j,int k,vector<vector<int>>&dp)
    {
        if(k>=multipliers.size())return 0;
        if(vis[i][k])return dp[i][k];
        int one =multipliers[k]*nums[i]+util(nums,multipliers,i+1,j,k+1,dp);
        int two=multipliers[k]*nums[j]+util(nums,multipliers,i,j-1,k+1,dp);
        vis[i][k]=1;
        return dp[i][k]=max(one,two);
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int m=nums.size();
        int n=multipliers.size();
        memset(vis,false,sizeof(vis));
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return util(nums,multipliers,0,m-1,0,dp);        
    }
};


