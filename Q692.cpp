class compare{
    public:
    bool operator()(pair<string,int>&a,pair<string,int>&b)
    {
        if(a.second!=b.second)return a.second<b.second;
        return a.first>b.first;        
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>pq;
        for(auto i:words)
        {
            mp[i]++;
        }
        vector<string>ans;
        for(auto i:mp){
            pq.push({i.first,i.second});
        }
        while(k--&&!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
