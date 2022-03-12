class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        int *ml=new int [n]();
        int *mr=new int [n]();
        int *min=new int [n]();
        int mxl=0;
        int mxr=0;
        for(int i=0;i<n;i++)
        {
            ml[i]=mxl;
            if(height[i]>mxl)
            {
                mxl=height[i];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            mr[i]=mxr;
            if(height[i]>mxr)
            {
                mxr=height[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            min[i]=ml[i]<mr[i]?ml[i]:mr[i];
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(min[i]>height[i])
            {
                sum+=(min[i]-height[i]);
            }
        }
        return sum;
        cout<<endl;

        
        return 0;
    }
};
