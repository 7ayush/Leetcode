class Solution {
public:
    int hammingDistance(int x, int y) {
        int count =0;
        while(x>0||y>0)
        {
            int a=x%2,b=y%2;
            count+=a^b;
            x=x/2;y=y/2;
        }
        return count;
    }
};
