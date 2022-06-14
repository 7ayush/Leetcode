class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>>pq;
        pq.push(1);
        int i=1;
        long x=0;
        while(!pq.empty())
        {
            if(x==pq.top()){
                pq.pop(); 
                continue;
            }
            x=pq.top();
            pq.pop();
            if(i==n)return (int)x;            
            pq.push(x*2);
            pq.push(x*3);
            pq.push(x*5);
            i++;
        }
        return 0;        
    }
};
