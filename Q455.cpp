class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        int j=0,count=0;
        for(int i=0;i<g.size();i++)
        {
            if(j>=s.size())return count;
            if(g[i]<=s[j])
            {
                count++;
                j++;
            }
        }
        return count;
    }
};

