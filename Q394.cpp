class Solution {
public:
    string decode(int &i,string s)
    {
        string number="";
        string str="";
        while(s[i]<='9'&&s[i]>='0')
        {
            number+=s[i];
            i++;
        }
        int no=number==""?1:stoi(number);
        i++;// Because of '['
        while(s[i]!=']')
        {
            if(isdigit(s[i]))str += decode(i,s);     // recursion
		    else str.push_back(s[i]);
		    i++;
        }
        string ans="";
        while(no--)ans+=str;
        return ans;

    }
    string decodeString(string s) 
    {        
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))ans+=decode(i,s);
            else ans+=s[i];
        }
        return ans;
    }
    
};

//Char Stack
class Solution {
public:
    string decodeString(string s)
    {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=']')
                st.push(s[i]);
            else
            {
                string ss="";
                while(!st.empty() && st.top()!='[')
                {
                    ss=st.top()+ss;
                    st.pop();
                }
            
                st.pop();
            
                string number="";
                while(!st.empty() && isdigit(st.top()))
                {
                   number=st.top()+number;
                   st.pop();
                }
            
                int k=stoi(number);
            
                while(k--)
                {
                   for(int j=0;j<ss.length();j++)
                       st.push(ss[j]);
                }
           }
        }
        
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
