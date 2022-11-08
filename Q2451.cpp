class Solution {
public:
    string make_key(vector<int>vec)
    {
        string ans="";
        for(auto i:vec)
        {
            ans+=to_string(i)+'-';
        }
        return ans;
    }
    
    string oddString(vector<string>& words) {
        unordered_map<string,vector<string>>mp;
        for(auto word:words)
        {
            vector<int>temp;
            for(int i=1;i<word.size();i++)
            {
                temp.push_back(word[i]-word[i-1]);
            }
            mp[make_key(temp)].push_back(word);
        }
        for(auto i:mp)
        {
            if(i.second.size()==1)
            {
                return i.second[0];
            }
        }
        return "";
    }
};
