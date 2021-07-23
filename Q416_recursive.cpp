class Solution {
public:
    bool util(vector<int>nums,int n,int **dp,int sum)
    {
        if(sum==0)return true;
        if(n==0)  return false;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        if(sum>=nums[n-1])
        {
            bool x=util(nums,n-1,dp,sum-nums[n-1])||util(nums,n-1,dp,sum);
            return dp[n][sum]=x;
        }
        else
        {
            return dp[n][sum]=util(nums,n-1,dp,sum);
        }
        
        
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];   
        }
        
        if(sum%2==1)return false;
        
        int **dp=new int*[nums.size()+1];
        sum=sum/2;
        for(int i=0;i<nums.size()+1;i++)
        {
            dp[i]=new int[sum+1];
        }
        for(int i=0;i<nums.size()+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                dp[i][j]=-1;
            }
        }
        return util(nums,nums.size(),dp,sum);
        // return isSubsetUtil(nums.size(),nums,sum,dp);
    }
