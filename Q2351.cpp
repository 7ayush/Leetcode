class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int>mp;
        for(auto c:s){
            mp[c]++;
            if(mp[c]==2)return c;
        }
        return '0';
    }
};
