class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        int ans=0;
        for(auto it:nums)mp[it]++;
    
        for(auto it:mp)
        {
            int freq=it.second;
            if(mp.count(it.first+1)>0)
            {
                freq+=mp[it.first+1];    
            }
            else
            {
                freq=0;
            }
            ans=max(ans,freq);
        }
        return ans;
    }
};
