class Solution {
public:
    static bool compare(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.second!=b.second)return a.second<b.second;
        return a.first<=b.first;
    }
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int>mp;
        for(int i=lo;i<=hi;i++)
        {
            int count=0;
            int j=i;
            while(j!=1)
            {
                if(mp.find(j)!=mp.end()){
                    mp[i]=mp[j]+count;
                    break;
                } 
                if(j&1)j=3*j+1;
                else j=j/2;
                count++;                    
            }
            if(mp.find(i)==mp.end())mp[i]=count;
        }
        vector<pair<int,int>>vec;
        for(int i=lo;i<=hi;i++)
        {
            vec.push_back({i,mp[i]});
        }
        sort(vec.begin(),vec.end(),compare);
        return vec[k-1].first;
    }
};
