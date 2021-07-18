class Solution {
public:
    
    int lengthOfLastWord(string s) 
    {
        int count=0;
        int len=s.length()-1;
        for(int i=len;i>=0;i--)
        {
            char c=s[i];
            if(count==0&&c==' ')
            {
                continue;
            }
            if(c==' ')
            {
                return count;
            }
            else
            {
                count++;
            }
        }    
        return count;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        while(i>=0 && s[i] == ' ') i--;
        int l=0;
        while(i>=0 && s[i--] != ' ') l++;
        return l; 
    }
};
