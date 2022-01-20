class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>sum(101,0);
        vector<int>fsum(101,0);
        
        for(int i=0;i<logs.size();i++)
        {
            sum[logs[i][0]-1950]++;
            sum[logs[i][1]-1950]--;
        }
        
        int maxYear=1950;
        int maxPop=sum[0];
        fsum[0]=sum[0];
        for(int i=1;i<sum.size();i++)
        {
            fsum[i]=sum[i]+fsum[i-1];
            if(fsum[i]>maxPop)
            {
                maxYear=i+1950;
                maxPop=fsum[i];
            }
        }
        return maxYear;        
    }
};
