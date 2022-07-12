//BFS
//TLE
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]=='1')return false;
        int count=0;
        vector<int>ans;
        int sum=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')ans.push_back(sum+1);
            else{
                sum++;
            } 
        }
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            int j=x+1;
            while(j<ans.size())
            {
                if(ans[j]-ans[x]+j-x>=minJump && ans[j]-ans[x]+j-x<=maxJump)
                {
                    q.push(j);
                    if(j==ans.size()-1)return true;
                }
                j++;
            }            
        }
        return false;
    }
};


//DFS TLE
class Solution {
public:
    int util(vector<int>&ans,vector<int>&dp,int i,int maxSum,int minSum)
    {
        if(dp[i]!=-1)return dp[i];
        if(i==ans.size()-1)return dp[i]=true;
        bool p=false;
        for(int j=i+1;j<ans.size();j++)
        {
            if(ans[j]-ans[i]+j-i>=minSum&&ans[j]-ans[i]+j-i<=maxSum)
            {
                p=p||util(ans,dp,j,maxSum,minSum);
                if(p==true)return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]=='1')return false;
        int count=0;
        vector<int>ans;
        int sum=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')ans.push_back(sum);
            else{
                sum++;
            } 
        }
        vector<int>dp(ans.size(),-1);
        util(ans,dp,0,maxJump,minJump);
        return dp[0];
    }
};

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back()=='1') return false;
        int lastMarked=0; // to avoid visiting the same index again 
        s[0]='r';
        for(int i=0;i<s.size();i++){
            if(s[i] != 'r') continue; 
            int maxJP=min(i+maxJump+1,(int)s.size());
            int minJP=max(lastMarked+1,i+minJump);
            for(int j=minJP;j<maxJP;j++){
                if(s[j]=='0') s[j]='r';
            }
            lastMarked=maxJP-1;
        }
        return s.back()=='r';
    }
};
