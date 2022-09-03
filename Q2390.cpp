class Solution {
public:
    string removeStars(string s) {
        stack<char>stk;
        for(auto c:s)
        {
            if(c!='*')stk.push(c);
            else
            {
                stk.pop();
            }
        }
        string ans="";
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
