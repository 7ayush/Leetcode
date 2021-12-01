class Solution {
public:
    int firstUniqChar(string s) {

        int freq[26]={0};
        for(char c:s)freq[c-'a']++;
        for(int i=0;i<s.size();i++)
        {
            if(freq[s[i]-'a']==1)return i;
        }
        return -1;   
    }
};


//Using hashmap
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(auto &c:s) mp[c]++;
        for(int i=0;i<s.size();i++) if(mp[s[i]]==1) return i;
        return -1;
    }
};
