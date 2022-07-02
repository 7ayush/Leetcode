class Solution {
public:
    int countOdds(int low, int high) {
        if(low==high)return low&1;
        int count=0;
        if(low&1){
            count++;
            low++;
        }
        if(high&1)
        {
            count++;
            high--;
        }
        return (high-low)/2+count;
    }
};



