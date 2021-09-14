//TLE
class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1=s.size();
        int l2=t.size();
        if(l1!=l2)return false;
        vector<int>h1(26,0);
        vector<int>h2(26,0);
        for(int i=0;i<l1;i++)
        {
            h1[s[i]-'a']++;
            h2[t[i]-'a']++;
        }
        return h1==h2;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>ans;
        ans.push_back({strs[0]});
        for(int i=1;i<strs.size();i++)
        {
            int found=false;
            for(int j=0;j<ans.size();j++)
            {
                if(isAnagram(ans[j][0],strs[i]))
                {
                    found=true;
                    ans[j].push_back(strs[i]);
                }
            }
            if(!found)
            {
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};

//Using sorting and map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<string,vector<string> > mymap;
        int n = strs.size();
        string temp;
        
        for(int i =0;i<n;++i)
        {
            temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(temp);
        }
        
        vector<vector<string> > result;
        
        for(auto itr=mymap.begin();itr!=mymap.end();++itr)
            result.push_back(itr->second);
        
        return result;
    }
};
