class Solution {
public:
    int largestInteger(int num) {
        vector<int>odd,even;
        int copy=num;
        while(copy>0)
        {
            int x=copy%10;
            x&1?odd.push_back(x):even.push_back(x);
            copy=copy/10;
        }
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end(),greater<int>());
        
        vector<int>ans;
        copy=num;
        int n=odd.size()+even.size();
        for(int i=0;i<n;i++)
        {
            ans.push_back(copy%10);
            copy=copy/10;
        }
        int j=0,k=0;
        for(int i=n-1;i>=0;i--)
        {
            if(ans[i]&1)
            {
                ans[i]=odd[j++];
            }
            else
            {
                ans[i]=even[k++];
            }
        }
        int x=0;
        for(int i=n-1;i>=0;i--)
        {
            x=x*10+ans[i];
        }
        return x;
    }
};

