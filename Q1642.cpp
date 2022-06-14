class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int sum=0;
        int index=0;
        for(int i=1;i<heights.size();i++)
        {
            if(heights[i]<heights[i-1]){
                index=i;
                continue;   
            }
            pq.push(heights[i]-heights[i-1]);            
            sum+=heights[i]-heights[i-1];
            while(sum>bricks&&ladders>0&&!pq.empty())
            {
                sum-=pq.top();
                pq.pop();
                ladders--;
            }
            if(sum<=bricks)index=i;
            else break;
        }
        return index;        
    }
};
