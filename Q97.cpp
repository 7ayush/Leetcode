// Recursively
class Solution {
public:
    bool util(string s1, string s2, string s3,int i=0,int j=0,int k=0)
    {
        if(i==s1.size()&&j==s2.size()&&k==s3.size())return true;
        if(i==s1.size())return s2.substr(j)==s3.substr(k);
        if(j==s2.size())return s1.substr(i)==s3.substr(k);
        
        if(s1[i]==s3[k]&&s2[j]==s3[k]){
            return util(s1,s2,s3,i+1,j,k+1)||util(s1,s2,s3,i,j+1,k+1);
        }
        if(s1[i]==s3[k])return util(s1,s2,s3,i+1,j,k+1);
        if(s2[j]==s3[k])return util(s1,s2,s3,i,j+1,k+1);
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size()+s2.size()!=s3.size())return false;
        return util(s1,s2,s3);
    }
};
// Memoization using map
class Solution {
public:
    bool util(string s1, string s2, string s3,int i,int j,int k,map<pair<int,pair<int,int>>,bool>&mp)
    {
        if(i==s1.size()&&j==s2.size()&&k==s3.size())return mp[{i,{j,k}}]=true;
        if(mp.find({i,{j,k}})!=mp.end())return mp[{i,{j,k}}];
        if(i==s1.size())return mp[{i,{j,k}}]=s2.substr(j)==s3.substr(k);
        if(j==s2.size())return mp[{i,{j,k}}]=s1.substr(i)==s3.substr(k);
        
        if(s1[i]==s3[k]&&s2[j]==s3[k]){
            return mp[{i,{j,k}}]=util(s1,s2,s3,i+1,j,k+1,mp)||util(s1,s2,s3,i,j+1,k+1,mp);
        }
        if(s1[i]==s3[k])return mp[{i,{j,k}}]=util(s1,s2,s3,i+1,j,k+1,mp);
        if(s2[j]==s3[k])return mp[{i,{j,k}}]=util(s1,s2,s3,i,j+1,k+1,mp);
        return mp[{i,{j,k}}]=false;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size()+s2.size()!=s3.size())return false;
        map<pair<int,pair<int,int>>,bool>mp;
        return util(s1,s2,s3,0,0,0,mp);
    }
};


//Memoization improvement
// Memoization using map
class Solution {
public:
    bool util(string s1, string s2, string s3,int i,int j,int k,map<pair<int,int>,bool>&mp)
    {
        if(i==s1.size()&&j==s2.size()&&k==s3.size())return mp[{i,j}]=true;
        if(mp.find({i,j})!=mp.end())return mp[{i,j}];
        if(i==s1.size())return mp[{i,j}]=s2.substr(j)==s3.substr(k);
        if(j==s2.size())return mp[{i,j}]=s1.substr(i)==s3.substr(k);
        
        if(s1[i]==s3[k]&&s2[j]==s3[k]){
            return mp[{i,j}]=util(s1,s2,s3,i+1,j,k+1,mp)||util(s1,s2,s3,i,j+1,k+1,mp);
        }
        if(s1[i]==s3[k])return mp[{i,j}]=util(s1,s2,s3,i+1,j,k+1,mp);
        if(s2[j]==s3[k])return mp[{i,j}]=util(s1,s2,s3,i,j+1,k+1,mp);
        return mp[{i,j}]=false;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size()+s2.size()!=s3.size())return false;
        map<pair<int,int>,bool>mp;
        return util(s1,s2,s3,0,0,0,mp);
    }
};

// Tabulation
class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        int a=s1.size(),b=s2.size(),c=s3.size();
        if(a+b!=c)return false;
        vector<vector<int>>dp(a+1,vector<int>(b+1,0));
        for(int i=0;i<=a;i++)
        {
            for(int j=0;j<=b;j++)
            {
                if(i==0&&j==0)dp[i][j]=1;
                else if(i==0)
                {
                    if(s2[j-1]==s3[j-1])
                        dp[i][j]=dp[i][j-1];
                }
                else if(j==0)
                {
                    if(s1[i-1]==s3[i-1])
                        dp[i][j]=dp[i-1][j];
                }
                else if(s1[i-1]==s3[i+j-1]&&s2[j-1]!=s3[i+j-1])
                    dp[i][j]=dp[i-1][j];
                
                else if(s1[i-1]!=s3[i+j-1]&&s2[j-1]==s3[i+j-1])
                    dp[i][j]=dp[i][j-1];
                
                else if(s1[i-1]==s3[i+j-1]&&s2[j-1]==s3[i+j-1])
                    dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
            }   
        }
        return dp[a][b];
    }
};
