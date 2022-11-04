https://leetcode.com/contest/weekly-contest-314/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxTime=logs[0][1],maxId=logs[0][0];
        for(int i=1;i<logs.size();i++)
        {
            if(maxTime<logs[i][1]-logs[i-1][1])
            {
                maxId=logs[i][0];
                maxTime=logs[i][1]-logs[i-1][1];
            }
            else if(maxTime==logs[i][1]-logs[i-1][1])
            {
                maxId=min(maxId,logs[i][0]);
            }
        }
        return maxId;
    }
};

