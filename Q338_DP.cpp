// In this question we make an array of size n+1 and initialise 0 index with 0 and index 1 2 4 8 16 and so on with 1
// the value of ans[i]=ans[nearest of of 2]-ans[difference]
class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int>ans(n+1,-1);
        ans[0]=0;
        if(n==0) return ans;
        int range=0;
        for(int i=1;i<=n;i*=2)
        {
            ans[i]=1;            
            range++;
        }
        range--;
        int diff=2;
        int i=2;
        while(range--)
        {
            int x=diff;
            int start=i;
            while(x--&&i<=n)
            {
                if(ans[i]!=-1)
                {
                    i++;
                    continue;
                }                
                ans[i]=ans[start]+ans[i-start];
                i++;
            }
            diff=diff*2;
        }
        return ans;      
    }
};


class Solution {
public:   
    vector<int> countBits(int n) {
        vector<int> res(n,0);
        res.push_back(0);
        if(n==0)
            return res;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
                res[i]=res[i/2];
            else
                res[i]=res[i-1]+1;
        }
        return res;
    }
};


class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> v(n + 1);
        v[0] = 0;
        unsigned int count = 0;
        for (int i = 1; i <= n; i++)
        {
            v[i] = v[i / 2] + i % 2;
        }

        return v;
    }
};
