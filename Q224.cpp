class Solution {
public:
    int calculate(string s) {
        
        stack<int>stk;
        int sign=1;
        int ans=0;
        int curr=0;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(c>='0'&&c<='9'){
                curr=c-'0';
                while(i+1<s.size()&&s[i+1]>='0'&&s[i+1]<='9')
                {
                    curr=curr*10+(s[i+1]-'0');
                    i++;
                }
                curr=curr*sign;
                cout<<curr<<" ";
                ans+=curr;
                curr=0;
                sign=1;
            }
            else if(c=='-') sign=-1;
            else if(c=='+') sign=1;
            else if(c=='(')
            {
                stk.push(ans);
                stk.push(sign);
                ans=0;
                sign=1;
            }
            else if(c==')')
            {
                int prevSign=stk.top(); stk.pop();
                ans=prevSign*ans;
                int prevAns=stk.top(); stk.pop();
                ans+=prevAns;
            }
        }
        return ans;
    }
};
