class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq(target.begin(),target.end());
        long int sum=0;
        for(auto i:target)sum+=i;
        while(pq.top()!=1)
        {
            int x=pq.top();
            pq.pop();
            sum-=x;
            if(x<=sum||sum<1)return false;
            x%=sum;
            sum+=x;
            pq.push(x?x:sum);
        }
        return true;
    }
};
