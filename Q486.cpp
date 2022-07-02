class Solution {
public:
    int solve(vector<int>& nums, bool turn ,int i, int j ){
        if(i>j)
            return 0;
        
        if(turn){
         return max(nums[i]+solve(nums,false,i+1,j),nums[j]+solve(nums,false,i,j-1));
        }
        
        else
           return min(solve(nums,true,i+1,j),solve(nums,true,i,j-1));
        
    }
    

    bool PredictTheWinner(vector<int>& nums) {
        
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        
        int sum1= solve(nums,true,0,nums.size()-1);
        
        int sum2=totalSum-sum1;
        
        return sum1>=sum2;
    }
};

//Recursive
class Solution {
public:
//     We need to return if a can win at all. This means i
    bool predict(vector<int>&nums,int i,int j,int score1,int score2,bool turn)
    {
        if(i>j)return score1>=score2;
        if(turn)
           return predict(nums,i+1,j,score1+nums[i],score2,!turn)||predict(nums,i,j-1,score1+nums[j],score2,!turn);
        return predict(nums,i+1,j,score1,score2+nums[i],!turn) && predict(nums,i,j-1,score1,score2+nums[j],!turn);
    }
    bool PredictTheWinner(vector<int>& nums) {
        return predict(nums,0,nums.size()-1,0,0,1);
    }
};
