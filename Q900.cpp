class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int>mp;
        string s1="qwertyuiopQWERTYUIOP";
        string s2="asdfghjklASDFGHJKL";
        string s3="zxcvbnmZXCVBNM";
        for(char c:s1)mp[c]=1;
        for(char c:s2)mp[c]=2;
        for(char c:s3)mp[c]=3;
        vector<string>vec;
        for(string word:words)
        {
            int one=mp[word[0]];
            bool flag=true;
            for(int i=0;i<word.size();i++)
            {
                if(mp[word[i]]!=one){
                    flag=false;
                    break;
                }
            }
            if(flag)vec.push_back(word);
        }
        return vec;
                
    }
};
