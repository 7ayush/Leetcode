class Solution {
public:
    int count(int n)
    {
        int c=0;
        while(n)c++,n=n/10;
        return c;
    }
    bool reorderedPowerOf2(int n) {
        vector<int>vec(10,0);
        int x=n;
        int c1=count(n);
        while(x)
        {
            vec[x%10]++;
            x=x/10;
        }
        for(int i=1;count(i)<=c1;i=i*2)
        {
            int x=i;
            vector<int>vec1(10,0);
            while(x)
            {
                vec1[x%10]++;
                x=x/10;
            }   
            if(vec==vec1)return true;
        }
        return false;
    }
};

