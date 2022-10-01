class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int>ans;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)sum+=nums[i];
        }
        for(auto i:queries)
        {
            int oldValue=nums[i[1]];
            int newValue=oldValue+i[0];
            
            sum+=oldValue%2==0? -oldValue : 0;
            sum+=newValue%2==0? newValue  : 0;
            nums[i[1]]=newValue;
            ans.push_back(sum);
        }
        return ans;
        
    }
};
