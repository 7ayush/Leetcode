//Recursive TLE

class Solution {
public:
    int util(vector<int>nums,int x,int i,int j,int count)
    {
        if(x==0)return count;
        if(i>j)return -1;
        int left=x<nums[i]?-1:util(nums,x-nums[i],i+1,j,count+1);
        int right=x<nums[j]?-1:util(nums,x-nums[j],i,j-1,count+1);
        if(left==-1)return right;
        if(right==-1)return left;
        return min(left,right);
    }
    int minOperations(vector<int>& nums, int x) {
        int ans=util(nums,x,0,nums.size()-1,0);
        return ans==0?-1:ans;
    }
};

//Memoization 
//TLE

class Solution {
public:
    int util(vector<int>nums,int x,int i,int j,int count,map<string,int>mp)
    {
        string key=to_string(i)+'*'+to_string(j)+'*'+to_string(x);
        if(mp[key]>0)return mp[key];
        if(x==0)return mp[key]=count;
        
        if(i>j)return mp[key]=-1;       
        
        int left=x<nums[i]?-1:util(nums,x-nums[i],i+1,j,count+1,mp);
        int right=x<nums[j]?-1:util(nums,x-nums[j],i,j-1,count+1,mp);
        if(left==-1)return mp[key]=right;
        if(right==-1)return mp[key]=left;
        return mp[key]=min(left,right);
    }
    int minOperations(vector<int>& nums, int x) {
        map<string,int>mp;
        int ans=util(nums,x,0,nums.size()-1,0,mp);
        return ans==0?-1:ans;
    }
};

//Using hashmap and prefix sum
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int,int>mp;
        int minAns=INT_MAX;        
        
        mp[0]=-1;
        mp[nums[0]]=0;
        
        for(int i=1;i<nums.size();i++)
        {
            nums[i]+=nums[i-1];
            mp[nums[i]]=i;
        }
        
        if(nums[nums.size()-1]<x)return -1;
        
        x=nums[nums.size()-1]-x;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i]-x)==1)
            {
                int len=i-mp[nums[i]-x];
                len=nums.size()-len;
                minAns=min(minAns,len);
            }
        }
        return minAns==INT_MAX?-1:minAns;
    }
};
