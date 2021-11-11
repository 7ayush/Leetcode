
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<long long>sum(nums.size());
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum[i]=sum[i-1]+nums[i];
        }
        int count=0;
        map<int,pair<int,int>>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(sum[i])!=m.end())
            {
                map<int,pair<int,int>>::iterator it=m.find(sum[i]-k);
                if(it!=m.end())
                {
                    m[sum[i]].second+=it->second.first;                        
                }
                m[sum[i]].first++;
            }
            else
            {
                map<int,pair<int,int>>::iterator it=m.find(sum[i]-k);
                int x=0;
                if(it!=m.end())
                {
                    x=it->second.first;                    
                }                
                m.insert({sum[i],{1,x}});
            }
        for(auto it :m)
        {
            if(it.first==k)
            {
                count+=it.second.first;                              
            }
            count+=it.second.second;
            
        }
        
        return count;
    }
};
