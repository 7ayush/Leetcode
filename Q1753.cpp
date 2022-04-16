// Priority Queue
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score=0;
        priority_queue<int>pq;
        if(a>0)pq.push(a);
        if(b>0)pq.push(b);
        if(c>0)pq.push(c);
        while(pq.size()>1)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            x--;
            y--;
            score++;
            if(x>0)pq.push(x);
            if(y>0)pq.push(y);
        }
        return score;
        
    }
};
