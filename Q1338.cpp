//Using priority queue
class compare{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;        
    }
};
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int count=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        map<int,int>mp;
        for(auto i:arr)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        int n=arr.size();
        while(n>arr.size()/2)
        {
            count++;
            n=n-pq.top().first;
            pq.pop();
        }
        return count;
    }
};

