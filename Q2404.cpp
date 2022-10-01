class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)if(i%2==0)mp[i]++;
        int mini=INT_MAX;
        int maxf=0;
        
        for(auto i:mp)
        {
            if(i.second>maxf)
            {                
                mini=i.first;
                maxf=i.second;
            }
            else if(i.second==maxf)
            {
                mini=min(mini,i.first);
            }
        }
        return mini==INT_MAX ?-1:mini;        
    }
};

