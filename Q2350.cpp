class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        map<int,vector<int>>mp;
        for(int i=0;i<rolls.size();i++)
        {
            mp[rolls[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        for(int i=1;i<=k;i++)if(mp.find(i)==mp.end())return 1;
        for(auto i:mp)q.push({i.first,i.second[0]});        
        
        int len=2;
        while(!q.empty())
        {
            int x=q.size();
            while(x--)
            {
                auto [val,lastIndex]=q.front();
                q.pop();
                for(auto i:mp)    //running from 1-n
                {
                    auto x=upper_bound(i.second.begin(),i.second.end(),lastIndex)-i.second.begin();
                    if(x==i.second.size())return len;
                    else
                        q.push({i.first,i.second[x]});
                }
            }
            len++;
        }
        return -1;
    }
};
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {

        int ans=1;
        unordered_set<int> s;

        for(int i:rolls){
            s.insert(i);
            if(s.size()==k){
                s.clear();
                ans++;
            }
        }
        return ans;
    }
};
