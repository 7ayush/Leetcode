class Solution {
public:
    int countBits(int x)
    {
        if(x==0)return 0;
        return (x&1)+countBits(x/2);
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;        
        unordered_set<string>s;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                string a=to_string(nums[i])+','+to_string(nums[j]);
                string b=to_string(nums[j])+','+to_string(nums[i]);
                if(s.find(a)!=s.end())continue;
                int x=nums[i]|nums[j];
                int y=nums[i]&nums[j];
                if(mp.find(x)==mp.end())mp[x]=countBits(x);
                if(mp.find(y)==mp.end())mp[y]=countBits(y);
                if(mp[x]+mp[y]>=k){
                    s.insert(a);                    
                    if(a==b){
                        count++;   
                    }
                    else
                    {
                        count+=2;
                        s.insert(b);   
                    } 
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) 
    {
        long long cnt[30] = {}, res = 0;
        for (int n : unordered_set<int>(begin(nums), end(nums)))
            ++cnt[__builtin_popcount(n)];
        for (int i = 1; i < 30; ++i)
            for (int j = max(i, k - i); j < 30; ++j)
                res += cnt[i] * cnt[j] * (i == j ? 1 : 2);
        return res;
    }
};
