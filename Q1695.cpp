class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        
        vector<int>nums1(nums.size()+1,0);
        nums1[0]=0;
        
        unordered_map<int,int>mp;
        int sum=0; int score=0; int ans=0; int last=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            nums1[i+1]=sum;
            if(mp.count(nums[i])>0)
            {
                last=max(last,mp[nums[i]]);                
            }
            score=nums1[i+1]-nums1[last+1];                
            mp[nums[i]]=i;
            ans=max(ans,score);
        }
        return ans;
    }
};
