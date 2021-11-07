// O(N^2) TC and O(N) space complexity
class Solution {
public:    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        set<vector<int>>unique;
        if(nums.size()<3)return ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++)
        {
            int curr=nums[i];
            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    vector<int>temp{nums[i],nums[l],nums[r]};
                    unique.insert(temp);
                    l++;r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0)
                {
                    l++;
                }
                else 
                {
                    r--;
                }
            }
        }
        for(vector<int>vec:unique)
        {
            ans.push_back(vec);
        }
        return ans;
    }
};
