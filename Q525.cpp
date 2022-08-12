class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            sum+=arr[i]==0 ? -1:1;
            if(mp.find(sum)!=mp.end())
                ans=max(ans,i-mp[sum]);
            else 
                mp[sum]=i;
        }
        return ans;
    }
};
