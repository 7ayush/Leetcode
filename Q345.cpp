class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        int n=s.size();
        int j=n-1;
        while(i<j)
        {
            while(i<n)
            {
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                {
                    break;
                }
                else i++;
            }
            while(j>=0)
            {
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U')
                {
                    break;
                }
                else j--;
            }
            if(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            } 
            else break;
        }
        return s;
    }
};
