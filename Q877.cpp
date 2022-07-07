//Game theory logic
class Solution {
public:
    bool util(vector<int>& piles,int start,int end,bool turn,int alice=0,int bob=0){
        if(start>end)return alice>=bob;
        if(turn==1)
        {
            return util(piles,start+1,end,!turn,alice+piles[start],bob)||util(piles,start,end-1,!turn,alice+piles[end],bob);
        }
        return util(piles,start+1,end,!turn,alice,bob+piles[start])&&util(piles,start,end-1,!turn,alice,bob+piles[end]);
    }
    bool stoneGame(vector<int>& piles) {
        int i=0,j=piles.size()-1;
        return util(piles,i,j,1);
    }
};
