//Recursive
class Solution {
public:
    int solve(int i, int k, vector<int>&nums){
        if(i >= nums.size()) return 0;
        int ans = INT_MIN;
        for(int j=1; j<=k; j++){
            ans = max(ans, nums[i] + solve(i+j, k, nums));
        }
        return ans;
    }
    int maxResult(vector<int>& nums, int k) {
        return solve(0, k, nums);
    }
};

//Memoized
class Solution {
public:
    int util(vector<int>& nums,int i,int k,vector<int>&dp,int n) 
    {
        if(i==nums.size()-1)return nums[i];
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        
        for(int j=i+1;j<min(i+k+1,n);j++)
        {
           ans = max(ans, util(nums,j,k,dp,n));        
        }
        ans+=nums[i];
        return dp[i]=ans;
    }
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(nums.size(),-1);
        return util(nums,0,k,dp,n);
    }
};


// Priority Queue
class Solution {
public:

int maxResult(vector<int>& nums, int k) {
    int sum=0;
    priority_queue<pair<int,int>>temp;
    int score=nums[0];
    temp.push({nums[0],0});
    for(int i=1;i<nums.size();i++)
    {
        while(!temp.empty()&&temp.top().second<i-k)
            temp.pop();
        score=nums[i]+temp.top().first;
        temp.push({score,i});
    }
    return score;
}
};
