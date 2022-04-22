class Solution {
public:
    int binaryGap(int n) {
        while(n%2==0)n=n>>1;
        int count=0;
        int maxCount=0;
        int oneCount=0;
        // cout<<n;
        while(n>0)
        {            
            if(n&1)
            {
                count=0;       
                oneCount++;
            }
            else
            {
                count++;
            }
            maxCount=max(maxCount,count);
            n=n>>1;
        }
        return oneCount==1?0:maxCount+1;
    }
};
