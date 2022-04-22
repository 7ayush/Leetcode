class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans=ans^s[i]^t[i];
        }
        ans=ans^t[t.size()-1];
        return ans;
    }
};
