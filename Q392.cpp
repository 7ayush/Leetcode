class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }               
        }
        return dp[n][m]==s.size();
        
    }
};


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


class Solution {
public:
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
