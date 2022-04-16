class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i:nums)
        {
            pq.push(i);
        }
        int prod=1;
        int k=2;
        while(k--&&!pq.empty())
        {
            prod*=pq.top()-1;
            pq.pop();
        }
        return prod;
    }
};
