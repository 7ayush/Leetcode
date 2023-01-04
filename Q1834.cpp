class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        vector<vector<int>>sortedTasks;
        for(int i=0;i<tasks.size();i++)
        {
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedTasks.begin(),sortedTasks.end());
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        long long currentTime=0;
        int i=0;

        while(i<sortedTasks.size()||!pq.empty())
        {
            if(pq.empty()&&currentTime<sortedTasks[i][0])
            {
                currentTime=sortedTasks[i][0];
            }
            while(i<sortedTasks.size()&&sortedTasks[i][0]<=currentTime)
            {
                pq.push({sortedTasks[i][1],sortedTasks[i][2]});
                i++;
            }
            auto [x,y]=pq.top();
            pq.pop();
            ans.push_back(y);
            currentTime+=x;
        }

        return ans;
    }
};
