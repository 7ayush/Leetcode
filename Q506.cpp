class compare{
    public:
    bool operator()(const pair<int,int>&a,const pair<int,int>&b)
    {
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        int n=score.size();
        for(int i=0;i<n;i++)
        {
            pq.push({score[i],i});
        }
        // cout<<pq.top().first<<" "<<pq.top().second;
        int k=1;
        vector<string>ans(n);
        while(k<=n)
        {
            if(k==1)
            {
                ans[pq.top().second]="Gold Medal";
            }
            else if(k==2)
            {
                ans[pq.top().second]="Silver Medal";
            }
            else if(k==3)
            {
                ans[pq.top().second]="Bronze Medal";
            }
            else
            {
                ans[pq.top().second]=to_string(k);
            }
            pq.pop();
            k++;
        }
        return ans;
    }
};
