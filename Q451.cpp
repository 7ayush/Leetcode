//Using priority queue

class compare{
    public:
    bool operator()(pair<int,char>&a,pair<int,char>&b){
        return a.first<b.first;        
    }
};
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,compare>pq;
        map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty())
        {
            int x=pq.top().first;
            char c=pq.top().second;
            while(x--)
            {
                ans+=c;
            }
            pq.pop();
        }
        return ans;
    }
};
