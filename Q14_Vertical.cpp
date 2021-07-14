// We need to find the Longest Common Prefix for a array of strings
// We can do so by Vertical screening as well
// O(n*n) Time complexity
// O(1) Space Complexity
class Solution {
public:
    
        
    string longestCommonPrefix(vector<string>& strs) 
    {
        
        string lcp="";
        for(int i=0;i<strs[0].size();i++)
        {
            char c=strs[0][i];
            bool same=true;
            for(int j=0;j<strs.size();j++)
            {
                if(strs[j][i]!=c||strs[j][i]=='\0')
                {
                    return lcp;
                }
            }
            lcp+=c;
        }
        
        return lcp;
        
        
    }
};
