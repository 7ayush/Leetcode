//Using PQ
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto i:nums)
        {
            pq.push(i);
        }
        int n=nums.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=pq.top();
            pq.pop();
        }
        return ans;        
    }
};
