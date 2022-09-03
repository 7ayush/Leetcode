class Solution {
public:
    void push(int n,int k,int i,vector<int>&ans)
    {
        if(n==1){
            ans.push_back(i);
            return;   
        }
        int x=i%10;
        if(x-k>=0)
        {
            push(n-1,k,i*10+x-k,ans);
            if(k==0)return;
        }
        if(x+k<=9)
        {
            push(n-1,k,i*10+x+k,ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            push(n,k,i,ans);
        }        
        return ans;
    }
};
