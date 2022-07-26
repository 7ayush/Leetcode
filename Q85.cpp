class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>mat(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')count++;
                else count=0;
                mat[i][j]=count;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)continue;
                else
                {
                    int width=INT_MAX;
                    int len=1;
                    for(int k=i;k>=0;k--)
                    {
                        if(mat[k][j]==0)break;
                        else
                        {
                            width=min(width,mat[k][j]);
                            ans=max(ans,width*len);                            
                        }
                        len++;
                    }
                }
            }
        }
        return ans;        
    }
};


// Maximum Area of Histogram Solution
class Solution {
public:
    vector<int>nsl(vector<int>row)
    {
        vector<int>ans(row.size());
        stack<int>s;
        for(int i=0;i<row.size();i++)
        {
            while(!s.empty()&&row[s.top()]>=row[i])
            {
                s.pop();
            }
            if(s.empty()) ans[i]=-1;
            else ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>nsr(vector<int>row)
    {
        vector<int>ans(row.size());
        stack<int>s;
        for(int i=row.size()-1;i>=0;i--)
        {
            while(!s.empty()&&row[s.top()]>=row[i])
            {
                s.pop();
            }
            if(s.empty()) ans[i]=-1;
            else ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>mat(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<m;j++)
            {
                if(matrix[j][i]=='1')count++;
                else count=0;
                mat[j][i]=count;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            vector<int>left=nsl(mat[i]);
            vector<int>right=nsr(mat[i]);            
            for(int j=0;j<n;j++)
            {
                int l=left[j]==-1?0:left[j]+1;
                int r=right[j]==-1?n-1:right[j]-1;
                ans=max(ans,(r-l+1)*mat[i][j]);
            }
        }
        return ans;        
    }
};

