class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int x=n-k;        
        for(int i=1;i<n;i++)
        {
            cardPoints[i]+=cardPoints[i-1];
        }
        if(n==k)return cardPoints[n-1];
        int ans=cardPoints[x-1];
        for(int i=x;i<n;i++)ans=min(ans,cardPoints[i]-cardPoints[i-x]);
        return cardPoints[n-1]-ans;
    }
};
