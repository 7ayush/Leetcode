// We need to find the Longest Common Prefix for a array of strings
// We can do so by Vertical screening and Horizontal Screening This is the code for Horizontal screening
// O(n*n) Time complexity
// O(1) Space Complexity
class Solution {
public:
    
        
    string longestCommonPrefix(vector<string>& strs) 
    {
        string lcp=*strs.begin();
        
        for(int i=1;i<strs.size();i++)   
        {
            string temp="";
            int size=min(lcp.size(),strs[i].size());
            if(size==0)return "";
            for(int j=0;j<size;j++)
            {
                if(strs[i][j]!=lcp[j])
                {
                    break;
                }
                else
                {
                    temp+=lcp[j];
                }
            }
            lcp=temp;
            // cout<<temp<<" ";
        }
        
        return lcp;
        
        
    }
};
