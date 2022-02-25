class Solution {
public:
    int longestPalindrome(string s) {

         int a[58]={0};
        for(int i=0;i<s.size();i++)
        {            
            a[s[i]-'A']++;   
        }
        int countEven=0;
        int countOdd=0;
        for(int i=0;i<58;i++)
        {
            if(a[i]&1)
            {
                countOdd++;
                countEven+=(a[i]/2)*2;
            }
            else
            {
                countEven+=a[i];
            }
        }
        if(countOdd>0)countOdd=1;
        return countEven+countOdd;
    }
};
