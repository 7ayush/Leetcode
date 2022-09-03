class Solution {
public:
    bool checkPalindrome(string s)
    {
        int start=0,end=s.size();
        while(start<end)
        {
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<n-1;i++)
        {
            string s="";
            int x=n;
            while(x>0)
            {
                s+=to_string(x%i);
                x=x/i;
            }
            if(checkPalindrome(s)==false)return false;
        }
        return true;
    }
};


class Solution {
public:    
    bool isStrictlyPalindromic(int n) {        
        return false;
    }
};

