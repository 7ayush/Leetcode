//TLE
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<vector<int>>map1(words1.size(),vector<int>(26,0));
        vector<vector<int>>map2(words2.size(),vector<int>(26,0));
        for(int i=0;i<words1.size();i++)
        {
            for(auto j:words1[i])
            {
                map1[i][j-'a']++;   
            }
        }
        for(int i=0;i<words2.size();i++)
        {
            for(auto j:words2[i])
            {
                map2[i][j-'a']++;   
            }
        }
        vector<string>ans;
        for(int i=0;i<words1.size();i++)
        {
            bool flag=true;
            for(int j=0;j<words2.size();j++)
            {
                for(int k=0;k<26;k++)
                {
                    if(map1[i][k]<map2[j][k])
                    {
                        flag=false;
                        break;
                    }
                }
                if(!flag)break;
            }
            if(flag)ans.push_back(words1[i]);
        }
        return ans;
    }
};


class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<vector<int>>map1(words1.size(),vector<int>(26,0));
        vector<int>map2(26,0);        
        vector<int>maps(26,0);        
        for(int i=0;i<words1.size();i++)
        {
            for(auto j:words1[i])
            {
                map1[i][j-'a']++;   
            }
        }
        for(int i=0;i<words2.size();i++)
        {
            vector<int>mp(26,0);
            for(auto j:words2[i])
            {
                mp[j-'a']++;   
            }
            for(int j=0;j<26;j++)
            {
                maps[j]=max(maps[j],mp[j]);
            }
        }
        vector<string>ans;
        for(int i=0;i<words1.size();i++)
        {
            bool flag=true;
            for(int j=0;j<26;j++)
            {
                if(map1[i][j]<maps[j]){
                    flag=false;
                    break;
                }
            }
            if(flag)ans.push_back(words1[i]);
        }
        return ans;
    }
};
