//Bruteforce solution

class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        if(a[0]>b[0])return true;
        return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>m;
        for(int i:nums)
        {
            m[i]++;
        }
        vector<vector<int>>order;
        for(auto it:m)
        {
            order.push_back({it.second,it.first});
        }
        sort(order.begin(),order.end(),compare);
        // for(int i=0;i<order.size();i++)
        // {
        //     cout<<order[i][0]<<" "<<order[i][1]<<endl;
        // }
        for(int i=0;i<k;i++)
        {
            ans.push_back(order[i][1]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//Using priority queue
class compare{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;        
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        map<int,int>mp;
        for(int i:nums)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push({i.first,i.second});
        }
        vector<int>ans;
        while(k--)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
            
        
    }
