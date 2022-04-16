//Priority Queue
class compare{
    public:
    bool operator()(pair<double,int>&a,pair<double,int>&b){
        return a.first>=b.first;        
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<double,int>,vector<pair<double,int>>,compare>pq;
        for(int i=0;i<points.size();i++)
        {
            double dist=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            pq.push({dist,i});
        }
        vector<vector<int>>vec;
        while(k--)
        {
            int i=pq.top().second;
            vec.push_back({points[i][0],points[i][1]});
            pq.pop();
        }
        return vec;
           
    }
};
