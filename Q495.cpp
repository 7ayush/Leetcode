//Using merge intervals
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        vector<int>start;
        vector<int>end;
        if(timeSeries.size()==1)return duration;
        for(int i=0;i<timeSeries.size();i++)
        {
            start.push_back(timeSeries[i]);
            end.push_back(timeSeries[i]+duration);
        }
        vector<vector<int>>ans;
        int s=start[0],e=end[0];
        for(int i=0;i<timeSeries.size()-1;i++)
        {
            if(e>=start[i+1])
            {
                e=max(e,end[i+1]);
            }
            else
            {
                ans.push_back({s,e});
                s=start[i+1];
                e=end[i+1];
            }
            if(i==timeSeries.size()-2)ans.push_back({s,e});
        }
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        }
        for(int i=0;i<ans.size();i++)
        {
            sum+=ans[i][1]-ans[i][0];
        }
        return sum;
        
    }
};

