class Solution {
public:
    vector<int>sl(vector<int>&heights)
    {
        int n=heights.size();
        vector<int>ans(heights.size());
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans[i]=-1;
                s.push(i);
            }
            else
            {
                while(!s.empty()&&heights[i]<=heights[s.top()])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=s.top();
                }
                s.push(i);
            }
        }
        return ans;
        
    }
    vector<int>sr(vector<int>&heights)
    {
        //0 1 2 3 4 5
        //2 1 5 6 2 3
        int n=heights.size();
        vector<int>ans(heights.size());
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                ans[i]=-1;
                s.push(i);
            }
            else
            {
                while(!s.empty()&&heights[i]<=heights[s.top()])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=s.top();
                }
                s.push(i);
            }
        }
        return ans;
        
    }
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        vector<int>nsl=sl(heights);
        vector<int>nsr=sr(heights);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int h=heights[i];
            int l=nsl[i]==-1?i+1:i-nsl[i];
            int r=nsr[i]==-1?n-i-1:nsr[i]-i-1;
            maxi=max(maxi,(l+r)*h);
        }
        return maxi;
    }
};
