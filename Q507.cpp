class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=0;
        if(num==1)return false;
        for(int i=1;i<=sqrt(num);i++)
        {
            if(i*(num/i)==num){
                sum+=i+num/i;  
            }
        }
        return sum==2*num;
    }
};
