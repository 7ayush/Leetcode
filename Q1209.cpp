class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>stk;
        for(char c:s)
        {
            if(!stk.empty()&&stk.top().first==c) stk.top().second++;
            else stk.push(make_pair(c,1));
            
            if(stk.top().second==k)stk.pop();
        }
        string ans="";
        while(!stk.empty())
        {
            pair<char,int>p=stk.top();
            stk.pop();
            while(p.second--)
            {
                ans+=p.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
