class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int>oddNum,evenNum,oddTarget,evenTarget;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)evenNum.push_back(nums[i]);
            else oddNum.push_back(nums[i]);
            
            if(target[i]%2==0)evenTarget.push_back(target[i]);
            else oddTarget.push_back(target[i]);
        }
        long long ans=0;
        for(int i=0;i<evenNum.size();i++)
        {
            if(evenNum[i]>evenTarget[i])ans+=(evenNum[i]-evenTarget[i])/2;
        }
        for(int i=0;i<oddNum.size();i++)
        {
            if(oddNum[i]>oddTarget[i])ans+=(oddNum[i]-oddTarget[i])/2;
        }
        
        return ans;
    }
};
