class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int m=word1.size();
        int n=word2.size();
        int i=0,j=0;
        while(i<m&&j<n)
        {
            ans+=word1[i++];
            ans+=word2[j++];            
        }
        while(i<m) ans+=word1[i++];
        while(j<n) ans+=word2[j++];
        return ans;
        
    }
};
