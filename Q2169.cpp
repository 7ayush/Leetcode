class Solution {
public:
    int countOperations(int num1, int num2) {
        int count=0;
        while(num1!=0&&num2!=0)
        {
            int y;
            if(num1>=num2)
            {
                y=num1/num2;
                num1=num1-y*num2;
            }
            else
            {
                y=num2/num1;
                num2=num2-y*num1;
            }
            count+=y;
        }
        return count;
    }
};
