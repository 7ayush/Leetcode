class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int first=-1;
        int second=-1;
        if(s1==s2)return true;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i]){
                if(first==-1)first=i;
                else second=i;
            }
        }
        if(first==-1||second==-1)return false;
        swap(s2[first],s2[second]);
        return s1==s2;
    }
};
