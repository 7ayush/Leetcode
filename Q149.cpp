class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1;
        for(int i=0;i<points.size();i++)
        {
            int x1=points[i][0],y1=points[i][1];
            map<double,int>mp;
            for(int j=i+1;j<points.size();j++)
            {
                int x2=points[j][0],y2=points[j][1];
                double slope=x2==x1 ? INT_MAX : (y2-y1)/(double)(x2-x1);
                if(mp.count(slope)==0){
                    mp[slope]=2;
                }
                else mp[slope]++;
                ans=max(ans,mp[slope]);
            }   
        }
        return ans;
    }
};
