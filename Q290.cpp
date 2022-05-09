class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>vec;
        string temp="";
        for(char c:s)
        {
            if(c!=' ') temp+=c;
            else
            {
                vec.push_back(temp);
                temp="";
            }
        }
        if(temp!="") vec.push_back(temp);        
        if(vec.size()!=pattern.size())return false;
        map<string,char>m;
        map<char,string>m1;
        for(int i=0;i<vec.size();i++)
        {
            char c=pattern[i];
            if(m.find(vec[i])==m.end())m[vec[i]]=c;
            else
            {
                if(m[vec[i]]!=c)return false;
            }
            
            if(m1.find(c)==m1.end())m1[c]=vec[i];
            else
            {
                if(m1[c]!=vec[i])return false;
            }
        }
        return true;        
    }
};
