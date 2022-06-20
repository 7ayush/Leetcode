class Solution {
public:
    string greatestLetter(string s) {
        vector<int>low(26,0);    
        vector<int>high(26,0);
        for(char c:s)
        {
            if(c>='a'&&c<='z')low[c-'a']=1;
            if(c>='A'&&c<='Z')high[c-'A']=1;
        }
        string ans="";
        for(int i=0;i<low.size();i++)
        {
            if(low[i]&&high[i])
            {
                ans="";
                ans+=i+'A';
            }
        }
        return ans;
    }
};
