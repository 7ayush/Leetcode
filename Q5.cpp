class Solution {
public:
    void printVector(vector<vector<int>>dp)
    {
        int n=dp.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }   
            cout<<endl;
        }
        cout<<endl;
    }
    string longestPalindrome(string str)
    {
        int n=str.size();
        vector<vector<int>>dp(n,vector<int>(n,0));        
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;            
        }
        
        int maxLen=1;
        int start=0,end=0;
        for(int i=0;i<n-1;i++)
        {            
            if(str[i]==str[i+1]){
                dp[i][i+1]=1;   
            }
        }
        for(int j=2;j<n;j++)
        {
            for(int i=0;i<j-1;i++)
            {
                if(dp[i+1][j-1]==1&&str[i]==str[j])
                {
                    dp[i][j]=1;                    
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==1&&j-i+1>maxLen)
                {
                    maxLen=j-i+1;
                    start=i;
                    end=j;
                }
            }   
        }
        string x=str.substr(start,(end-start+1));
        return x;      
    }
    
};
