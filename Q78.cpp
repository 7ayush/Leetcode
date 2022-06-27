class Solution {
public:
    void util(vector<int>& nums,int i,vector<vector<int>>&ans,vector<int>temp)
    {
         if(i==nums.size()){
             ans.push_back(temp);
             return;
         }
        util(nums,i+1,ans,temp);
        temp.push_back(nums[i]);
        util(nums,i+1,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        util(nums,0,ans,{});
        return ans;
    }
};


// Using Bit Manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};
