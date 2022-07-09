class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        for(int i=0;i<s.size();)    
        {
            if(i+2<s.size()&&s[i+2]=='#'){
                int x=stoi(s.substr(i,2))-1;
                ans+=('a'+x);  
                i+=3;
            }
            else
            {
                ans+= s[i]-'0'+'a'-1;
                i++;
            }
        }
        return ans;
    }
};
