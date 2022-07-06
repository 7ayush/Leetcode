class Solution {
public:
    int nC2(int n)
    {
        int x=n;
        int y=n-1;
        if(x&1)y=y/2;
        else x=x/2;
        return x*y;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int sum=0;
        for(auto i:nums){
            
            sum=sum+i;
            if(sum<0){
                int x=abs(sum)/k+1;
                sum+=x*k;
            }
            sum=sum%k;
            mp[sum]++;   
        }
        int count=0;
        for(auto i :mp)
        {
            if(i.first==0)count+=i.second;
            count+=nC2(i.second);
        }
        return count;        
    }
};
