class Solution {
public:
    string sum(string s1,string s2)
    {
        string ans="";
        int carry=0;
        int m=s1.size()-1;
        int n=s2.size()-1;
        while(m>=0||n>=0)
        {
            int x=m>=0?s1[m--]-'0':0;
            int y=n>=0?s2[n--]-'0':0;
            x=x+y+carry;
            ans=to_string(x%10)+ans;
            carry=x/10;            
        }
        if(carry)ans=to_string(carry)+ans;
        return ans;
        
    }
    string multiply(string num1, string num2) {
        if(num1.size()<num2.size())return multiply(num2,num1);
        if(num1=="0"||num2=="0")return "0";
        vector<string>add(num2.size());
        int m=num1.size(),n=num2.size();
        for(int i=0;i<n;i++)
        {
            int x=num2[n-i-1]-'0';
            string ans="";
            int carry=0;
            for(int j=m-1;j>=0;j--)
            {
                int y=num1[j]-'0';
                y=x*y+carry;
                carry=y/10;
                ans=to_string(y%10)+ans;
            }
            if(carry)ans=to_string(carry)+ans;
            for(int j=0;j<i;j++)
            {
                ans+='0';
            }
            add.push_back(ans);
        }
        for(int i=1;i<add.size();i++)
        {
            add[i]=sum(add[i],add[i-1]);
        }
        return add[add.size()-1];
    }
    
};
