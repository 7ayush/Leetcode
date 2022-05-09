class Solution {
public:
    vector<int> constructRectangle(int area) {
        int len=sqrt(area);
        for(int i=len;i<=area;i++)
        {
            int x=area/i;
            if(i*x==area)
            {
                if(i>x)return {i,x};
                return {x,i};
            }
        }
        return {};
        
    }
};
