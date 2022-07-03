class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>>hash(words.size(),vector<int>(26,0));
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                int c=words[i][j]-'a';
                hash[i][c]++;
            }
        }
        vector<string>ans;
        for(int j=0;j<26;j++)
        {
            int count=INT_MAX;
            for(int i=0;i<words.size();i++)
            {
                count=min(count,hash[i][j]);
            }
            while(count>0)
            {
                string x="";
                x+=(j+'a');
                ans.push_back(x);               
                count--;
            }
        }
        return ans;
                
    }
};
