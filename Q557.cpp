class Solution {
public:
    void reverse(string &s,int i,int j)
    {
        int n=s.size();
        if(i>=n||j>=n)return;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;j--;
        }
    }
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        while(j<n)
        {
            while(s[j+1]!=32&&s[j+1]!='\0')j++;
            reverse(s,i,j);
            i=j+2; 
            j++;
        }
        return s;
    }
};
