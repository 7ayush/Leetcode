class Solution {
public:
    string makeGood(string s) {
        string ans="";
        stack<char>stk;
        for(int i=0;i<s.size();i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else
            {
                if(stk.top()-'a'+'A'==s[i]||stk.top()-'A'+'a'==s[i])
                {
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
        }
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
