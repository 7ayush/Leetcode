class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &i:image)
        {
            reverse(i.begin(),i.end());
        }
        for(int i=0;i<image.size();i++)            
        {
            for(int j=0;j<image[i].size();j++)            
            {
                image[i][j]=!image[i][j];
            }
        }
        return image;
    }
};
