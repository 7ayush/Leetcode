class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);        
        int n=intervals.size();
        int j=n-1;
        while(j>=1&&intervals[j-1][0]>intervals[j][0])
        {
            swap(intervals[j-1][0],intervals[j][0]);
            swap(intervals[j-1][1],intervals[j][1]);            
            j--;
        }

        if(n==1)return intervals;
        vector<vector<int>>ans;
        int start=intervals[0][0];
        int end=intervals[0][1];
        
        int i=0;
        while(i<n-1)
        {
            if(end>=intervals[i+1][0])
            {
                end=max(end,intervals[i+1][1]);       
            }
            else
            {
                ans.push_back({start,end});
                start=intervals[i+1][0];
                end=intervals[i+1][1];
            }
            if(i==n-2)ans.push_back({start,end});
            i++;            
        }
        return ans;
    }
};
