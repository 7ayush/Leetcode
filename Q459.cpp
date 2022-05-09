class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int maxSize=s.size()/2;
        for(int i=1;i<=maxSize;i++)
        {
            if(s.size()%i!=0)continue;
            string x=s.substr(0,i);
            int repeat=s.size()/i;
            string temp="";
            while(repeat--)
            {
                temp+=x;
            }
            if(temp==s)return true;
        }
        return false;
    }
};

