class compare{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b)
    {
        return a.first>b.first;//minheap
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(auto i:nums)mp1[i]++;
        for(auto i:numsDivide)mp2[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(auto i:mp1)pq.push({i.first,i.second});
        int count=0;
        while(!pq.empty())
        {
            auto [x,y]=pq.top();
            bool flag=false;
            for(auto i:mp2)
            {
                if(i.first%x!=0){
                    count+=y;
                    flag=true;
                    break;
                }
            }
            if(!flag)return count;
            pq.pop();
        }
        if(pq.empty())return -1;
        return count;
    }
};
