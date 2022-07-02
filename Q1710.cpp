class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        return a[1]>=b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int count=0;
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int i=0;
        while(truckSize>=0&&i<boxTypes.size())
        {
            int take=min(truckSize,boxTypes[i][0]);
            count+=take*boxTypes[i][1];
            truckSize-=take;
            i++;
        }
        return count;
    }
};
