// Storing non zero elements in another array and then pushing 0 in the end to fill up space O(N) time O(N) space very inefficient
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                ans.push_back(nums[i]);
            }
        }
        int x=nums.size()-ans.size();
        for(int i=0;i<x;i++)
        {
            ans.push_back(0);
        }
        nums=ans;
    }
};

// 2 pointer theorem to push zeros to the end O(N) time and O(1) space
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int k=0;
        int i=0;
        while(i<n)
        {
            if(nums[i]==0)
            {
                count++;
                i++;
            }
            else
            {
                nums[k++]=nums[i++];
            }
        }
        i=n-1;
        while(count--)
        {
            nums[i]=0;
            i--;
            
        }
        
    }
};
