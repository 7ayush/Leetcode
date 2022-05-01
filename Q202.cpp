class Solution {
public:
    int sos(int n)
    {
        int ans=0;
        while(n>0)
        {
            int x=n%10;
            ans+=x*x;
            if(ans<0)return -1;
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        set<int>s;
        while(n!=1)
        {
            int n1=sos(n);
            if(n1==-1)return false;
            if(s.find(n1)!=s.end())return false;
            s.insert(n1);
            n=n1;
        }
        return true;
    }
};

