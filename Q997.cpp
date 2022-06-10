// By creating a graph
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>graph(n+1,vector<int>(n+1,0));
        for(auto it:trust)
        {
            graph[it[0]][it[1]]=1;
        }
        int ans=-1;
        for(int j=1;j<=n;j++)
        {
            bool flag=false;
            for(int i=1;i<=n;i++)
            {
                if(graph[i][j]==0&&i!=j){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ans=j;
                break;
            }
        }
        if(ans==-1)return -1;
        for(int j=1;j<=n;j++)
        {
            if(graph[ans][j]!=0&&ans!=j)return -1;
        }
        return ans;
            
        
    }
};

    


// Using Frequencies
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int>count1(n+1,0);
        vector<int>count2(n+1,0);        
        for(auto it:trust)
        {
            count1[it[0]]++;
            count2[it[1]]++;            
        }
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<count1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<count2[i]<<" ";
        // }
        // cout<<endl;
        for(int i=1;i<=n;i++)
        {
            if(count1[i]==0&&count2[i]>=n-1)return i;
        }
        return -1;
        
    }
};
