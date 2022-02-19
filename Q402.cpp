class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        string ans="";
        if(k==num.size())return "0";
        for(int i=0;i<num.size();i++)
        {
            while(k>0&&s.size()&&s.top()>num[i])
            {
                k--;
                s.pop();
                if(k==0)break;                
            }
            s.push(num[i]);
        }
        if(k>0)
        {
            while(s.size()&&k>0)          
            {
                s.pop();
                k--;
            }
        }
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
        int i=0;
        while(i<ans.size()&&ans[i]=='0')
        {
            i++;
        }
        ans=ans.substr(i);
        return ans==""?"0":ans;
        
    }
};

