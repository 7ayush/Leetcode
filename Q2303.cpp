class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double sum=0;
        int x=0,i=0;
        while(x<income)
        {
            int y=min(brackets[i][0],income);
            sum+=(y-x)*brackets[i][1]/100.0;
            x=y;
            i++;
        }
        return sum;
    }
};
