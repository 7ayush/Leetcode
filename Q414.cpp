class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        set<int>s;
        for(int i:nums)s.insert(i);
        for(auto i:s)
        {
            pq.push(i);
            if(pq.size()>3)pq.pop();
        }
        if(pq.size()<3)
        {
            while(pq.size()!=1)pq.pop();
        }
        return pq.top();
    }
};
