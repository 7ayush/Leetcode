class Solution {
public:
    pair<int,int>minDistance(vector<int>edges,int node1,int node2)
    {
        unordered_map<int,int>mp;
        int dist=0;
        int node=node1;
        int ans=INT_MAX;
        int minDist=INT_MAX;
        pair<int,int>fin;
        vector<int>vis(edges.size()+1,0);
        
        while(node!=-1){
            if(vis[node])break;
            vis[node]=1;
            mp[node]=dist++;
            node=edges[node];
        }
        dist=0;
        node=node2;
        vector<int>vis1(edges.size()+1,0);
        while(node!=-1)
        {
            if(vis1[node])break;
            vis1[node]=1;
            if(mp.find(node)!=mp.end())
            {
                int curr=max(mp[node],dist);
                if(curr<=minDist)
                {
                    if(curr==minDist)ans=min(ans,node);
                    else ans=node;
                    minDist=curr;
                }
                    
            }
            dist++;
            node=edges[node];
        }
        return {minDist,ans};
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int>mp;
        
        pair<int,int>p1=minDistance(edges,node1,node2);
        int ans;
        ans=p1.second;
        return ans==INT_MAX?-1:ans;
    }
};
