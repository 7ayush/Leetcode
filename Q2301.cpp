// Get all substrings of size 4
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        if(sub.size()>s.size())return false;
        vector<vector<int>>hash(129,vector<int>(129,0));
        
        for(auto i:mappings)hash[i[0]][i[1]]=1;
        
        int n=sub.size();
        int m=s.size();
        for(int i=0;i<=m-n;i++)
        {
            string x=s.substr(i,n);
            bool flag=true;
            for(int j=0;j<n;j++)
            {
                if(x[j]==sub[j])continue;
                else
                {
                    if(hash[sub[j]][x[j]]==0){
                        flag=false;
                        break;
                    }
                    else continue;
                }
            }
            if(flag){
                return true;   
            }
        }
        return false;
    }
};
