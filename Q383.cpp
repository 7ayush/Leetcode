class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        for(char c:ransomNote)
        {
            hash1[c-'a']++;
        }
        for(char c:magazine)
        {
            hash2[c-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(hash1[i]>hash2[i])return false;
        }
        return true;
    }
};

