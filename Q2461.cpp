class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long runningSum=0;
        long long ans=0; 
        unordered_map<int,int>mp;
        int i=0,j=0;
        int n=nums.size();
        
        while(j<n)
        {
            if(mp.find(nums[j])!=mp.end())
            {
                int idx=mp[nums[j]];
                while(i<=idx)
                {
                    runningSum-=nums[i];
                    mp.erase(nums[i]);
                    i++;
                }
            }
            runningSum+=nums[j];
            mp[nums[j]]=j;            
            if(j-i+1==k)
            {
                ans=max(ans,runningSum);
                runningSum-=nums[i];
                mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
        
    }
};

/*
Approach is to store the elements in a map and using sliding window technique
check if the size of map is equal to k on each window. The window which has map size equal to k
is having distict elements.

1. Store first k elements in the map.
2. Then keep traversing through the array and adding the new one to the map and 
removing the old one(i-k th) element form the map if its count is zero.
3. Do same for the total sum, add ith value and remove i-k th value.
4. Maximize ans by taking max sum value. 
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        unordered_map<int, int> mp;
        int i = 0;
        while(i < k  && i < nums.size()){ // store first k elements in the map
            mp[nums[i]]++;
            sum += nums[i];
            i++;
        }
        if(mp.size() == k) ans = sum; // if all distinct, then ans = sum 
        while(i < nums.size()){
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0) mp.erase(nums[i-k]);
            
            sum += nums[i];
            sum -= nums[i-k];
            if(mp.size() == k) ans = max(ans, sum);
            i++;
        }
        return ans;
    }
};
