// TLE
class Solution {
public:
    string make_key(int a,int b)
    {
        string ans=to_string(a)+'-'+to_string(b);
        return ans;
    }
    int mod;
    long long util(int start,int end,int k,unordered_map<string,int>&mp)
    {
        string key=make_key(start,k);
        if(k==0&&start==end)return mp[key]=1;        
        if(k==0)return mp[key]=0;
        if(start<-1000||start>2001)return mp[key]=0;
        if(mp.find(key)!=mp.end())return mp[key];
        long long ans=(util(start+1,end,k-1,mp)+util(start-1,end,k-1,mp))%mod;
        return mp[key]=ans;
        
    }
    int numberOfWays(int start, int end, int k) {
        mod=1e9+7;
        unordered_map<string,int>mp;        
        return util(start,end,k,mp);
    }
};

class Solution {
public:
    int dp(int i,int &endPos, int k,vector <vector <int>> &cache){
        if(i==endPos && k==0)return 1;        
        if(k<=0)return 0;
        
        if(cache[i][k]!=-1)return cache[i][k];
        
        return cache[i][k]=(dp(i+1,endPos,k-1,cache)+dp(i-1,endPos,k-1,cache))%1000000007;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        int diff=abs(endPos-startPos);
        
        // conditions for which answer will always be 0
        if(diff>k || (diff%2==1 && k%2==0) || (diff%2==0 && k%2==1)){
            return 0;
        }
        
        // just shifting start and end positions by same quantity
        // max value of k can be 1000 so if we have startpos as 0 then (startpos-k) would have been negative so shifting startPos and endPos save us from these cases 
        startPos+=1200;
        endPos+=1200;
        
        vector <vector <int>> cache(4000,vector <int> (k+1,-1));
        return dp(startPos,endPos,k,cache);
    }
};
