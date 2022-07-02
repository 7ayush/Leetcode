class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDist=INT_MAX;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target)return target;
                else if(sum>target) k--;
                else j++;
                if(minDist>abs(sum-target)){
                    ans=sum;
                    minDist=abs(sum-target);
                }                
            }
        }
        return ans;
    }
};

