class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {     
        unordered_map<string,int>mp;
        for(auto i:words)
        {
            mp[i]++;
        }
        int len=words[0].size();
        vector<int>ans;
        int a=s.size()-len*words.size();
        for(int i=0;i<=a;i++)
        {
            unordered_map<string,int>mp1=mp;
            int j=i;
            int count=words.size();
            while(j+len<=s.size()&&mp1.find(s.substr(j,len))!=mp1.end())
            {
                string x=s.substr(j,len);
                mp1[x]--;
                if(mp1[x]==0)mp1.erase(x);
                j+=len;
                count--;
            }
            if(count==0)ans.push_back(i);
        }
        return ans;
    }
};
