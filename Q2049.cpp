class Solution {
public:
    int util(vector<int>&dp,map<int,vector<int>>&children,int root)
    {
        if(children[root].size()==0)return dp[root]=1;
        if(dp[root]!=-1)return dp[root];
        int count=0;
        for(int i=0;i<children[root].size();i++)
            count+=util(dp,children,children[root][i]);
        return dp[root]=1+count;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        map<int,vector<int>>children;
        for(int i=0;i<parents.size();i++)
        {
            children[i]={};
        }
        int root=-1;
        for(int i=0;i<parents.size();i++)
        {
            if(parents[i]==-1)root=i;
            else children[parents[i]].push_back(i);                
        }

        vector<int>nodesBelow(parents.size(),-1);
        util(nodesBelow,children,root);
        
        vector<long long int>scores;
        for(int i=0;i<parents.size();i++)
        {
            int score1=1,score2=1,score3=1;//left right parent
            
            if(children[i].size()>=1)
            {
                score1=nodesBelow[children[i][0]];
            }
            if(children[i].size()==2)
            {
                score2=nodesBelow[children[i][1]];
            }
            if(i!=root)
                score3=nodesBelow[root]-nodesBelow[i];            
            long long int ans=1LL*score1*score2*score3;
            scores.push_back(ans);
        }
        map<long long int,int,greater<long long int>>mp;
        for(auto i:scores)mp[i]++;
        return mp.begin()->second; 
    }
};
