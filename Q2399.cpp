class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(mp.find(c)!=mp.end())
            {
                if((i-mp[c]-1)!=distance[c-'a'])return false;
            }
            else
            {
                mp[c]=i;
            }
        }
        return true;
    }
};
