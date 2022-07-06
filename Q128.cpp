// Method-1 
// Sorting and then traversing.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;        
        int count=1;
        int maxCount=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]+1==nums[i])count++;
            else if(nums[i-1]==nums[i])continue;
            else count=1;
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};
//Method-2
//While using hashset we are only iterating over unvisited groups
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> num_set(nums.begin(), nums.end());
        for (int num : nums) {
            if (num_set.find(num - 1) == num_set.end()) {
                int curr_num = num;
                int curr_len = 1;
                while (num_set.find(curr_num + 1) != num_set.end()) {
                    curr_num++;
                    curr_len++;
                }
                max_len = max(max_len, curr_len);
            }
        }
        return max_len;
    }
};
