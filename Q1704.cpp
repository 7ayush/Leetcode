class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    }
    bool halvesAreAlike(string s) {
        int count1=0;
        int count2=0;
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(isVowel(s[i]))
            {
                count1++;
            }
            if(isVowel(s[j]))
            {
                count2++;
            }
            i++;j--;
        }
        return count1==count2;
    }
};
