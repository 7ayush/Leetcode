class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>temp(1000002,0);
        for(auto i:intervals)
        {
            temp[i[0]]++;
            temp[i[1]+1]--;
        }
        int ans=temp[0];
        int sum=ans;
        for(int i=1;i<=1000002;i++)
        {
            sum+=temp[i-1];
            ans=max(ans,sum);
        }
        return ans;           
    }
};
