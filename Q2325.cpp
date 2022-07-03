class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char>mp;
        char a='a';
        for(int i=0;i<key.size();i++)
        {
            if(key[i]>='a'&&key[i]<='z'&&mp.count(key[i])==0)mp[key[i]]=a++;
        }
        string ans="";
        for(int i=0;i<message.size();i++)
        {
            if(message[i]>='a'&&message[i]<='z')
                message[i]=mp[message[i]];
        }
        return message;
    }
};
