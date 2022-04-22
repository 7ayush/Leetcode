class Solution {
public:
    int numberOfSteps(int num) {
        int x=0;
        while(num>0)
        {
            if(num&1){
                x++;
                num=num-1;
            }
            else{
                num=num/2;
                x++;
            }
            
        }
        return x;
    }
};
