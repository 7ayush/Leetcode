class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        if(a[2]<b[2])return true;
        else if(a[2]==b[2])return a[1]<b[1];
        return false;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),compare);
       
        int high=trips[trips.size()-1][2];
        
        vector<int>dp(high+1,0);
        for(auto i:trips)
        {
            dp[i[1]]+=i[0];
            dp[i[2]]-=i[0];
        }
        if(dp[0]>capacity)return false;
        for(int i=1;i<dp.size();i++)
        {
            dp[i]+=dp[i-1];
            if(dp[i]>capacity)return false;
        }
        return true;
    }
};

