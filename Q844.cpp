class Solution {
public:
    string optimise(string s)
    {
        string s1="";
        int count=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!='#'){
                if(count>0) count--;
                else s1+=s[i];   
                
            }
            else count++;
        }
        return s1;
    }
    bool backspaceCompare(string s, string t) {
        string s1=optimise(s);
        string t1=optimise(t);
        return s1==t1;
    }
};
