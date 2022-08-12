class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long>mp;
        long long int added=0;
        long long count=0;
        for(int i=0;i<tasks.size();i++)
        {
            if(mp.find(tasks[i])!=mp.end())
            {
                int x=i+added-mp[tasks[i]]-1;
                if(x<space)
                {
                    added+=space-x;                    
                }
            }
            mp[tasks[i]]=i+added;
            // cout<<tasks[i]<<" "<<added<<" "<<mp[tasks[i]]<<endl;
        }
        return tasks.size()+(long long)added;
    }
};
