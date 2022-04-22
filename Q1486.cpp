class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        int x;
        for(int i=0;i<n;i++)
        {
            x=start+i*2;
            ans=ans^x;
        }
        return ans;
    }
};
