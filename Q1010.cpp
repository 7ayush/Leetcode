class Solution {
public:
    int comp(int n)
    {
        int x=n;
        int y=n-1;
        if(x&1)y=y/2;
        else x=x/2;
        return x*y;
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        int count=0;
        int c1=0;
        for(auto it:time){            
            if(it%60==0)c1++;
            else mp[it%60]++;
        }
        
        for(auto &it:mp){
            if(it.first==30)count+=comp(mp[30]);
            else count+=it.second*mp[60-it.first];
            it.second=0;
        }
        count+=comp(c1);
        return count;
    }
};
