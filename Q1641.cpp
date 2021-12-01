// Recursive solution based on choices 
class Solution {
public:
    void util(int i,int *count,int n,int idx=0)
    {
        if(i>5)return;
        
        if(idx==n){           
            *count=*count+1;  
            return;
        }         
        util(i,count,n,idx+1);
        util(i+1,count,n,idx);        
    }
    int countVowelStrings(int n) {
        int count=0;
        util(1,&count,n);
        return count;
    }
};

// Based on pattern recognition
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>ans(5,1);
        for(int i=1;i<=n;i++)
        {
            for(int i=3;i>=0;i--)
            {
                ans[i]=ans[i]+ans[i+1];
            }
        }
        return ans[0];
    }
};

// Making a table 
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(6,0));
        for(int i=1;i<=5;i++)
        {
            dp[1][i]=i;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=5;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }   
        }
        return dp[n][5];
    }
};
