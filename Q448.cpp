//Using the swap-sort method
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int i=0;
        while(i<nums.size()){
            if(nums[i] != nums[nums[i]-1])  {
                swap(nums[i],nums[nums[i]-1]);
            }
            else
                i++;
            }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i+1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
//Using extra space to store if found or not
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>found(nums.size(),false);
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            found[nums[i]-1]=true;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!found[i])
                ans.push_back(i+1);
        }
        return ans;
    }
};
