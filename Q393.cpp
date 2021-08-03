 bool isSubsequence(string s, string t) 
    {
         int i=0;
         int size = s.length();
    
         for(char ch:t)
         {
             if(ch==s[i])
             {
                i++; 
             }
                
         }
             
    
         return (i==size);
    }

//Recusive solution not recursive
class Solution {
public:
    bool util(string s,string t)
    {
        if(s.length()==0)return true;
        if(t.length()==0)return false;
        
        if(s[0]==t[0])return util(s.substr(1),t.substr(1));
        return util(s,t.substr(1));
        
            
        
    }
    bool isSubsequence(string s, string t) 
    {
        return util(s,t);
    }
};


//Using recursion and starting from behind
bool util(string s,string t,int ls,int lt)
    {
        if(ls==-1)return true;
        if(lt==-1)return false;
        
        if(s[ls]==t[lt])return util(s,t,ls-1,lt-1);
        return util(s,t,ls,lt-1);
        
            
        
    }
    bool isSubsequence(string s, string t) 
    {
        return util(s,t,s.size()-1,t.size()-1);
    }
};
