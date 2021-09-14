// This is a sliding window problem wherein we are checking if two strings are having same frequency of digits within a window size if yes then they are permutation of each other
class Solution {
public:
    bool checkInclusion(string s1, string s2) {        
        int l1=s1.size();
        int l2=s2.size();
        if(l1>l2)return false;
        vector<int>h1(26,0);
        vector<int>h2(26,0);
        int l=0,r=0;
        while(r<l1)
        {
            h1[s1[r]-'a']++;
            h2[s2[r]-'a']++;
            r++;
        }
        while(r<=l2)
        {
            if(h1==h2)return true;            
            h2[s2[l]-'a']--;
            if(r<l2)
                h2[s2[r]-'a']++;
            l++;
            r++;
        }
        return false;
    }
};
