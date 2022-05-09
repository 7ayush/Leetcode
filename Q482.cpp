class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string n="";
        for(char c:s) if(c!='-')n+=c;
        
        reverse(n.begin(),n.end());
        
        vector<string>s1;
        string temp="";
        int k1=k;
        
        for(char c:n)
        {
            if(c>='a'&&c<='z')c=c-'a'+'A';
            if(k1--)temp+=c;                
            else
            {
                k1=k-1;   
                s1.push_back(temp);
                temp=c;
            }
        }
        if(temp!="")s1.push_back(temp);
        string ans="";
        reverse(s1.begin(),s1.end());
        for(int i=0;i<s1.size();i++)
        {
            reverse(s1[i].begin(),s1[i].end());
            ans+=s1[i];
            if(i!=s1.size()-1)ans+='-';
        }
        return ans;
    }
};
