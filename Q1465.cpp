class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxV=horizontalCuts[0];
        int maxH=verticalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++)
        {
            maxV=max(maxV,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++)
        {
            maxH=max(maxH,verticalCuts[i]-verticalCuts[i-1]);
        }
        long long exp=1e9+7;
        maxV=max(maxV,h-horizontalCuts[horizontalCuts.size()-1])%exp;
        maxH=max(maxH,w-verticalCuts[verticalCuts.size()-1])%exp;
        long long int ans=1LL*maxV*maxH;
        ans=ans%exp;
        return ans;
    }
};
