class Solution {
public:    
    char low(vector<int> & freq)
    {    
        for(int i=0;i<26;i++){
            if(freq[i]!=0)return 'a'+i;
        } 
        return 'z';  
    }
    string robotWithString(string s) {
        
        stack<char> stk;
        string ans="";  
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:s){
            stk.push(c);
            freq[c-'a']--; 
            while(!stk.empty() && stk.top()<=low(freq)){
                char x = stk.top(); 
                ans+= x;
                stk.pop();  
            }    
        }
        return ans;
    }
};
