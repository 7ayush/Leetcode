//Following the pattern it is related to square and fibonacci series
class Solution {
public:
    int countHousePlacements(int n) {
        int mod=1e9+7;
        vector<long long>fib{1,1};
        for(int i=0;i<n;i++)
        {
            fib.push_back((fib[fib.size()-1]+fib[fib.size()-2])%mod);
        }
        long long int ans=(fib[n+1]*fib[n+1])%mod;
        return ans;
    }
};

//Recursion + Memoization 
class Solution {
public:
    int util(vector<int>&dp,int n)
    {
        if(n<=0)return 1;
        if(dp[n]!=-1)return dp[n];
        int choose=util(dp,n-2);
        int notChoose=util(dp,n-1);
        int mod=1e9+7;
        long long int ans=(choose+notChoose)%mod;
        return dp[n]=ans;
    }
    int countHousePlacements(int n) {
        int mod=1e9+7;
        vector<int>dp(n+1,-1);
        long long int ans=(1LL*util(dp,n)*util(dp,n))%mod;
        return ans;
    }
};
