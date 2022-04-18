class compare{
    public:
    bool operator()(pair<char,int>&a,pair<char,int>&b){
        return a.second<b.second;        
    }
};
class Solution {
public:
    string getLast(string ans)
    {
        int n=ans.size();
        if(ans.size()<=2)return ans;
        string s=ans.substr(n-2,n-1);
        return s;
    }
    string getC(char c)
    {
        string s="";
        s+=c;
        s+=c;
        return s;
    }
    string strWithout3a3b(int a, int b,int c=0) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        string ans="";
        if(a>0)pq.push({'a',a});
        if(b>0)pq.push({'b',b});
        if(c>0)pq.push({'c',c});
        pair<char,int>p,q;
        while(pq.size()>=2)
        {
            p=pq.top();
            pq.pop();
            if(getLast(ans)==getC(p.first))
            {
                q=pq.top();
                pq.pop();       
                ans+=q.first;
                q.second=q.second-1;
                if(p.second>0)pq.push(p);
                if(q.second>0)pq.push(q);    
            }
            else
            {
                ans+=p.first;
                p.second=p.second-1;
                if(p.second>0)pq.push(p);
            }
            
        }
        if(!pq.empty())
        {
            p=pq.top();
            int x=p.second;
            while(x--&&getLast(ans)!=getC(p.first))
            {
                ans+=p.first;    
            }
        }
        
        
        return ans;
    }
    
};
