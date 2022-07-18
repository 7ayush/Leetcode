class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>visited;
        unordered_map<int,int>visitedBus;
        for(int i=0;i<routes.size();i++)
        {
            for(auto it:routes[i])
            {
                mp[it].push_back(i);
            }
        }
        int count=0;
        queue<int>q;
        q.push(source);
        while(!q.empty())
        {
            int x=q.size();            
            while(x--)
            {
                int station=q.front();
                q.pop();
                visited[station]=true;
                if(station==target)return count;
                for(auto i:mp[station])
                {
                   if(visitedBus[i])continue;
                   visitedBus[i]=true;
                   for(auto j:routes[i])
                   {
                       if(!visited[j])q.push(j);
                   }
                }                
            }
            count++;            
        }
        return -1;        
        
    }
};

