class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n>=0)return pos(x,n);
        else return neg(x,n);
    }

    double pos(double x,int n)
    {
        if(n==0)return 1;
        double res=pos(x,n/2);
        if(n%2==0)return res*res;
        else return x*res*res;
     }
    
    double neg(double x,int n)
    {
        if(n==0)return 1;
        double res=neg(x,n/2);
        if(n%2==0)return res*res;
        else return (1/x)*res*res;
    }
            
     
};
