class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        vector<int>g(n,0),p(n,0),m(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<garbage[i].size();j++)
            {
                if(garbage[i][j]=='M')
                {
                    m[i]++;
                }
                else if(garbage[i][j]=='G')
                {
                    g[i]++;
                }
                else if(garbage[i][j]=='P')
                {
                    p[i]++;
                }
            }
            if(i!=0){
                g[i]+=g[i-1];
                p[i]+=p[i-1];
                m[i]+=m[i-1];
            }
        }
        int gl=g[n-1];
        int ml=m[n-1];
        int pl=p[n-1];
        vector<int>cost(n,0);
        for(int i=1;i<n;i++)
        {
            cost[i]=cost[i-1]+travel[i-1];
        }
        // for(auto i:g)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:m)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:p)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:cost)cout<<i<<" ";
        // cout<<endl;
        bool gf=1,mf=1,pf=1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(g[i]==gl&&gf)
            {
                ans+=g[i];
                ans+=cost[i];
                gf=0;
            }
            if(m[i]==ml&&mf)
            {
                ans+=m[i];
                ans+=cost[i];
                mf=0;
            }
            if(p[i]==pl&&pf)
            {
                ans+=p[i];
                ans+=cost[i];
                pf=0;
            }
        }
        return ans;
    }
};

