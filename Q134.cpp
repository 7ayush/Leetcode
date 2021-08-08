// In this question we are iterating i from 0 to n-1. and then for that i we will run j from i to i-1 such that (i+1)%n=j and check if one sum is gasSum is more than costSum or not if difference is less then we will remove previously computed range
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int gasSum,costSum,res=-1,n=gas.size(),j,i;
        for(i=0;i<gas.size();i++)
        {
            gasSum=0;costSum=0;
            j=i;
            do
            {
                gasSum=gasSum+gas[j];
                costSum=costSum+cost[j];
                if(gasSum<costSum)
                {
                    if(j>i)i=j;
                    break;
                }
                j=(j+1)%n;
            }while(j!=i);
            if(gasSum>=costSum)
            {
                res=i;
                break;
            }            
        }
        return res;
    }
};
