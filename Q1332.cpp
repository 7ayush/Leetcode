/*
Only 3 cases can be there

1) if string is empty return 0 
2) If string is palindrome return 1
3) If string is not a palindrome the answer is supposed to be 2 because in first step all a can be removed and in second step all b can be removed.
*/

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0) return 0;
        string str=s;
        reverse(str.begin(),str.end());
        if(s==str) return 1;
        return 2;
    }
};
