class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>vec(n+1,0);
        vec[1]=1;
        int mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+delay;j<i+forget&&j<=n;j++)
            {
                long long sum=vec[j]+vec[i];
                sum%=mod;
                vec[j]=sum;
            }
        }
        long long int count=0;
        for(int i=0;i<forget;i++)
        {
            count=(count+vec[n-i])%mod;
        }
        return count;
    }
};
