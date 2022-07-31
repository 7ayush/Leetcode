class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            unordered_map<char,char>mp;
            unordered_map<char,char>rmp;
            bool flag=true;
            for(int j=0;j<pattern.size();j++)
            {
                if(mp.find(words[i][j])!=mp.end())   
                {
                    if(mp[words[i][j]]!=pattern[j]){
                       flag=false;   
                       break;
                    }                     
                }
                else
                {
                    mp[words[i][j]]=pattern[j];
                }
                if(rmp.find(pattern[j])!=rmp.end())   
                {
                     if(rmp[pattern[j]]!=words[i][j])
                     {
                        flag=false;   
                        break;
                     }                     
                 }
                else
                {
                    rmp[pattern[j]]=words[i][j];
                }                
            }
            if(flag)ans.push_back(words[i]);
        }
        return ans;
    }
};
