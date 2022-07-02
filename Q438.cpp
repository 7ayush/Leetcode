class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())return {};
        int n=p.size();
        vector<int>h1(26,0);
        vector<int>h2(26,0);
        vector<int>ans;
        
        for(char c:p)h1[c-'a']++;
        
        
        for(int i=0;i<n;i++)
        {
            h2[s[i]-'a']++;            
        }
        if(h1==h2)ans.push_back(0);
        for(int i=1;i+n-1<s.size();i++)
        {
            h2[s[i-1]-'a']--;
            h2[s[i+n-1]-'a']++;
            if(h1==h2)ans.push_back(i);
        }
        return ans;
        
    }
};
