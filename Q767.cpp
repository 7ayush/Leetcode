//Using priority queue
class compare{
    public:
    bool operator()(pair<char,int>&a,pair<char,int>&b){
        return a.second<b.second;        
    }
};
class Solution {
public:
    char lastChar(string s)
    {
        if(s=="")
        {
            return 0;
        }
        return s[s.size()-1];
    }
    string reorganizeString(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        string ans="";
        map<char,int>mp;
        for(char i:s)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push(i);
        }
        pair<char,int>p,q;
        
        while(pq.size()>=2)
        {
            p=pq.top();
            pq.pop();
            if(p.first==lastChar(ans))
            {
                q=pq.top();
                pq.pop();
                ans+=q.first;
                q.second=q.second-1;
                if(q.second>0)pq.push(q);
            }
            else
            {
                ans+=p.first;
                p.second=p.second-1;
            }
            if(p.second>0)pq.push(p);
        }
        if(pq.size()==1)
        {
            p=pq.top();
            if(p.first==lastChar(ans)||p.second>1)return "";
            ans+=p.first;
        }
        return ans;
    }
};
