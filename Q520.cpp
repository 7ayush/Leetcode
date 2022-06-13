class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int first=0;
        int upper=0;
        int lower=0;
        for(int i=0;i<word.size();i++)
        {
            if(i==0)
            {
                if(word[i]>='A'&&word[i]<='Z')first++;
            }
            if(word[i]>='A'&&word[i]<='Z')upper++;
            if(word[i]>='a'&&word[i]<='z')lower++;
        }
        return upper==word.size()|| lower==word.size()||(first==1&&lower==word.size()-1);
    }
};
