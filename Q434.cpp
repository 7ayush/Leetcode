class Solution {
public:
    int countSegments(string s) {
        vector<string>hash;
        string temp="";
        for(char c:s)
        {
            if(c!=' ')temp+=c;
            else
            {
                if(temp!="")hash.push_back(temp);
                temp="";
            }
        }
        if(temp!="")hash.push_back(temp);
        return hash.size();
    }
};
