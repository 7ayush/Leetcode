class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto i:arr)mp[i]=1;
        sort(arr.begin(),arr.end());
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    int a=arr[i]/arr[j];
                    if(mp.find(a)!=mp.end())
                    {
                        long long x=(mp[arr[i]]+1LL*mp[a]*mp[arr[j]])%mod;
                        mp[arr[i]]=x;
                    }                    
                }
            }
        }
        int sum=0;
        for(auto i:mp)
        {
            sum=(sum+i.second)%mod;
        }
        return sum;
    }
};
