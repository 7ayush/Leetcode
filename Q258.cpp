class Solution {
public:
    int s(int num)
    {
        int sum=0;
        while(num>0)
        {
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int addDigits(int num) {
        int sum=0;
        while(sum>=10||num>0)   
        {
            sum=s(num);
            if(sum>=10)
            {
                num=sum;
            }
            else num=0;
        }
        return sum;
    }
};
