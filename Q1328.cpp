class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1)return "";
        
        for(int i=0;i<n;i++)
        {
            if(palindrome[i]!='a'&&i!=n/2){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[palindrome.size()-1]='b';
        return palindrome;
    }
};
