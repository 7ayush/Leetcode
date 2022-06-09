class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int l=0,r=grid[0].size()-1,up=0,down=grid.size()-1;
        while(l<r&&up<down)
        {
            // For storing elements in an array
            vector<int>vec;
            for(int i=up;i<=down;i++)
            {
                vec.push_back(grid[i][l]);
            }
            for(int i=l+1;i<=r;i++)
            {
                vec.push_back(grid[down][i]);
            }
            for(int i=down-1;i>=up;i--)
            {
                vec.push_back(grid[i][r]);
            }
            for(int i=r-1;i>l;i--)
            {
                vec.push_back(grid[up][i]);
            }
            // for rotating the elements as per the number of times    
            int k1=k%vec.size();
            reverse(vec.begin(),vec.begin()+vec.size()-k1);            
            reverse(vec.begin()+vec.size()-k1,vec.end());            
            reverse(vec.begin(),vec.end());           
            
            //Putting the elements back into the grid as per the required pattern.             
            int k=0;
            for(int i=up;i<=down;i++)
            {
                grid[i][l]=vec[k++];
            }
            for(int i=l+1;i<=r;i++)
            {
                grid[down][i]=vec[k++];
            }
            for(int i=down-1;i>=up;i--)
            {
                grid[i][r]=vec[k++];
            }
            for(int i=r-1;i>l;i--)
            {
                grid[up][i]=vec[k++];
            }
            l++;up++;down--;r--;            
        }
        return grid;        
    }
};

