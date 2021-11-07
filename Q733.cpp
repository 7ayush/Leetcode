//DFS
class Solution {
public:
    void dfs(vector<vector<int>>&image,vector<vector<bool>>&visited,int i,int j,int newColor,int r,int c,int color)
    {
        if(i<0||j<0||i>=r||j>=c)
        {
            return;
        }
        if(image[i][j]==color&&visited[i][j]==false)
        {
            image[i][j]=newColor;
            visited[i][j]=true;
            dfs(image,visited,i-1,j,newColor,r,c,color);
            dfs(image,visited,i+1,j,newColor,r,c,color);
            dfs(image,visited,i,j-1,newColor,r,c,color);
            dfs(image,visited,i,j+1,newColor,r,c,color);              
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int r=image.size();
        int c=image[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,0));
        dfs(image,visited,sr,sc,newColor,r,c,image[sr][sc]);
        return image;
    }
};
