//using marking negative
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int i =0;
        while(i<nums.size())
        {
            int temp = abs(nums[i]);
            if(nums[temp - 1] > 0){nums[temp - 1] *= -1;}
            else{ans.push_back(temp);}
            i++;
        }        
        return ans;
    }
};


//cycle sort
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }
        for(i = 0; i < n; i++){
            if(nums[i] != i + 1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
