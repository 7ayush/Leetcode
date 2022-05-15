class Solution {
public:
    int maxConsecutive(int start, int end, vector<int>& special) {
        int ans=INT_MIN;
        sort(special.begin(),special.end());
        int i=0;
        int n=special.size();
        while(start<=end&&i<special.size())
        {
            ans=max(ans,special[i]-start);
            start=special[i]+1;
            i++;
        }
        ans=max(ans,end-start+1);
        return ans;
    }
};
