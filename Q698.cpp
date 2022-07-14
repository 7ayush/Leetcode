//DFS + DP TLE
class Solution {
public:
     bool util(vector<int>& nums,vector<int>&visited,int i,int k,int sum,int target)
    {
        if(k==0)return true;
        if(sum==target)return util(nums,visited,0,k-1,0,target);
        for(int j=i;j<nums.size();j++)
        {
            if(visited[j]||sum+nums[j]>target)continue;
            visited[j]=true;
            if(util(nums,visited,j+1,k,sum+nums[j],target))return true;
            visited[j]=false;
        }
        return false;
    }    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto i:nums)sum+=i;
        if(sum%k!=0)return false;
        sum=sum/k;
        vector<int>visited(nums.size(),0);
        return util(nums,visited,0,k,0,sum);
        
    }
};


//Minor changes works fine now
//DFS +visited
class Solution {
public:
    bool util(vector<int>& nums,vector<bool>&visited,int i,int k,int sum,int target)
    {
        if(k==1)return true;        
        if(sum==target)return util(nums,visited,0,k-1,0,target);
        if(i==visited.size())return false;
        if(sum>target)return false;
        for(int j=i;j<nums.size();j++)
        {
            if(visited[j])continue;
            visited[j]=true;
            sum+=nums[j];
            if(util(nums,visited,j+1,k,sum,target))return true;
            sum=sum-nums[j];            
            visited[j]=false;
            if(sum==0)break;
        }
        return false;
    }    
    bool canPartitionKSubsets(vector<int>& nums,int k) {
        int sum=0;        
        for(auto i:nums){
            sum+=i;   
        }
        if(nums.size()<k||sum%k!=0)return false;
        sum=sum/k;
        sort(nums.begin(),nums.end());
        vector<bool>visited(nums.size(),0);
        return util(nums,visited,0,k,0,sum);
    }
};
