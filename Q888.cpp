class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        int alice=accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        int bob=accumulate(bobSizes.begin(),bobSizes.end(),0);
        int avg=(alice+bob)/2;
        int ma=avg-alice;
        int mb=avg-bob;
        for(int i:aliceSizes)
        {
            if(find(bobSizes.begin(),bobSizes.end(),avg-alice+i)!=bobSizes.end())
                return {i,avg-alice+i};            
        }
        return {-1};
        
    }
};
