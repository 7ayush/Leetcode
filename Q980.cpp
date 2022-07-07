class Solution {
public:
    void traverse(vector<vector<int>>& grid,vector<vector<int>>visited,int i,int j,int &count,int cnt1,int cnt2)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==-1)return;
        if(visited[i][j])return;
        visited[i][j]=1;
        if(grid[i][j]==2){
            count+=cnt1-1==cnt2;
            return;
        }        
        traverse(grid,visited,i-1,j,count,cnt1+1,cnt2);
        traverse(grid,visited,i+1,j,count,cnt1+1,cnt2);
        traverse(grid,visited,i,j-1,count,cnt1+1,cnt2);
        traverse(grid,visited,i,j+1,count,cnt1+1,cnt2);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        pair<int,int>start;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                count+=grid[i][j]==0;
                if(grid[i][j]==1)start={i,j};
            }
        }
        int cnt=0;
        traverse(grid,visited,start.first,start.second,cnt,0,count);
        return cnt;        
    }
};
