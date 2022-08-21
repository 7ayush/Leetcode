class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words){
        unordered_set<string>s;
        vector<string>vec={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string a="";
        for(auto i:words)
        {
            for(char c:i)
            {
                a+=vec[c-'a'];
            }
            s.insert(a);
            a="";
        }
        return s.size();
    }
};
