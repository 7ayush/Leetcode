// We are using stacks Initialise stack with -1. 
// ( push i
// ) pop and then if s.empty() push i else len=max(i-s.top(),len)
// return length
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        stk.push(-1);
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if(stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    len=max(i-stk.top(),len);
                }
                
            }
        }
        return len;
    }
};
