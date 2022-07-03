// Simple recursive solution
class Solution {
public:
    void util(vector<vector<int>>&ans,vector<int>& candidates,int target,vector<int>temp,int i)
    {
        if(target<0||i==candidates.size())return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        util(ans,candidates,target,temp,i+1);
        temp.push_back(candidates[i]);
        util(ans,candidates,target-candidates[i],temp,i);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        util(ans,candidates,target,{},0);
        return ans;
    }
};
