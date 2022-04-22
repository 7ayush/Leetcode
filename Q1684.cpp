class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>allow(26,0);
        int count=0;
        bool flag=false;
        for(char i:allowed){
            allow[i-'a']=1;
        }
        for(string word:words)
        {
            flag=true;
            for(char letter:word)
            {
                if(allow[letter-'a']==0){
                    flag=false;
                    break;                    
                }
                
            }
            if(flag)count++;
        }
        return count;
        
    }
};
