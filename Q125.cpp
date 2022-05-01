class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(char c:s)
        {
            if((c>='a'&&c<='z')||(c>='0'&&c<='9'))
            {
                ans+=c;
            }
            else if(c>='A'&&c<='Z')
            {
                c=c-'A'+'a';
                ans+=c;
            }
            
        }
        string ans1=ans;
        reverse(ans.begin(),ans.end());
        return ans1==ans;
    }
};

