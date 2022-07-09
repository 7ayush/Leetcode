class Solution {
public:
    bool check(char word1,char word2,string order)
    {
        bool one=false;
        
        for(char c:order)
        {
            if(c==word2&&one==false)return false;
            if(c==word2)return true;
            if(c==word1)one=true;
        }
        return true;

    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<words.size()-1;i++)
        {
            int j=0;
            int k=0;
            while(j<words[i].size()&&k<words[i+1].size()&&words[i][j]==words[i+1][k])
            {
                j++;
                k++;
            }
            if(j<words[i].size()&&k==words[i+1].size())
            {
                return false;
            }
            if(j<words[i].size()&&k<words[i+1].size())
            {
                if(!check(words[i][j],words[i+1][k],order))return false;
            }            
        }
        return true;
    }
};
