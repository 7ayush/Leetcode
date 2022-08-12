class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long count=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int diff=nums[i]-i;
            if(mp[diff]){
                count+=mp[diff];
            }
            mp[diff]++;
        }
        
        long long totalPairs=(long long)(n-1)*(long long)(n)/2;
        
        return totalPairs-count;
    }
};
