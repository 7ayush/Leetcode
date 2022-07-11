//BFS Solution because DFS stucks in a loop
class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        int steps=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                int x=q.front();
                if(x==arr.size()-1)return steps;
                q.pop();
                if(x-1>=0)
                {
                    if(mp.find(arr[x-1])!=mp.end())
                    {
                        q.push(x-1);
                    }
                        
                }
                if(x+1<arr.size())
                {
                    if(mp.find(arr[x+1])!=mp.end())
                    {
                        q.push(x+1);
                    }                        
                }
                for(auto i:mp[arr[x]])
                {
                    if(mp.find(arr[i])!=mp.end()&&i!=x)
                    {
                        q.push(i);
                    }
                }
                mp.erase(arr[x]);
            }
            steps++;
        }
        return steps;
    }
};
