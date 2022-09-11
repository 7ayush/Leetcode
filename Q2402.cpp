class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meets) {
    int cnt[101] = {};
    sort(begin(meets), end(meets));
    priority_queue<int, vector<int>, greater<int>> avail;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
    for (int i = 0; i < n; ++i)
        avail.push(i);
    for (auto &m : meets) {
        while (!busy.empty() && busy.top().first <= m[0]) {
            avail.push(busy.top().second);
            busy.pop();
        }
        long long start = avail.empty() ? busy.top().first : m[0], duration = m[1] - m[0];
        int room = avail.empty() ? busy.top().second : avail.top();
        if (avail.empty())
            busy.pop();
        else
            avail.pop();
        ++cnt[room];
        busy.push({start + duration, room});
    }
    return max_element(begin(cnt), end(cnt)) - begin(cnt);
}
};


class Solution {
public:
    void printMap(vector<vector<int>>&mp)
    {
        for(auto i:mp)
        {
            cout<<i[0]<<" "<<i[1]<<endl;
        }
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>mp(n,vector<int>(2,0));
        printMap(meetings);
        cout<<endl;
        int delay=0;
        for(int i=0;i<meetings.size();i++)
        {
            int mini=0;
            int minTime=mp[0][0];
            for(int j=0;j<n;j++)
            {
                if(mp[j][0]<delay+meetings[i][0])
                {
                    mini=j;
                    minTime=mp[j][0];
                    break;
                }
                else
                {
                    if(minTime>mp[j][0])
                    {
                        minTime=mp[j][0];
                        mini=j;
                    }                    
                }
                
            }
            if(minTime>delay+meetings[i][0])
            {
                delay+=minTime-(delay+meetings[i][0]);
            }
            mp[mini][0]=meetings[i][1]+delay;
            mp[mini][1]+=1;
            printMap(mp);
            cout<<endl;
        }
        int maxi=0;
        int maxf=0;
        for(int i=0;i<n;i++)
        {
            if(maxf<mp[i][1])
            {
                maxf=mp[i][1];
                maxi=i;
            }
        }
        return maxi;
    }
};
