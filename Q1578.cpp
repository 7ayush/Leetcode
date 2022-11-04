class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost=0;
        for(int i=0;i<colors.size();)
        {
            int sum=neededTime[i];
            int maxi=neededTime[i];
            if(i+1<=colors.size()&&colors[i]!=colors[i+1]){
                i++;
                continue;
            }
            while(i+1<colors.size()&&colors[i]==colors[i+1])
            {
                sum+=neededTime[i+1];
                maxi=max(maxi,neededTime[i+1]);
                i++;
            }
            totalCost+=(sum-maxi);
        }
        return totalCost;
    }
};
