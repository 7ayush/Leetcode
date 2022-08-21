class Solution {
public:
    string largestPalindromic(string s) {
        vector<int>hash(10,0);
        for(auto i:s)hash[i-'0']++;
        int len=0;
        int odd=0;
        int maxOdd=0;
        for(int i=9;i>=0;i--)
        {
            len=len+(hash[i]/2)*2;
            if(hash[i]%2){
                odd=1;
                maxOdd=max(maxOdd,i);
            }
        }
        len+=odd;
        string ans(len,'0');
        int j=0;        
        for(int i=9;i>=0;i--)
        {
            int x=hash[i]/2;
            
            for(int k=0;k<x;k++)
            {
                ans[j]=i+'0';
                ans[len-j-1]=i+'0';
                j++;
            }
        }
        if(odd) ans[j]=maxOdd+'0';
        if(ans[0]=='0'){
            ans="";
            for(int i=9;i>=0;i--)
            {
                if(hash[i]){
                    ans+=(i+'0');
                    break;
                }
            }
        }
        return ans;
    }
};
