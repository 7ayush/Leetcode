// Using the 2 pointer approach to solve it
// Logic is pretty simple we change the lesser of i,j height because that is acting as a leggard to maxvolume
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int vol=(j-i)*min(height[i],height[j]);
        while(i<j)
        {
            if(height[i]<height[j])
            {
                i++;                
            }
            else 
            {
                j--;                
            }
            vol=max(vol,(j-i)*min(height[i],height[j]));
        }
        return vol;
    }
};
