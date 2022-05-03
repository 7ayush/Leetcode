// nlogn solution due to sorting
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>nums1=nums;
        sort(nums1.begin(),nums1.end());
        int left=0;
        int right=n-1;
        while(left<n-1&&nums1[left]==nums[left])
        {
            left++;
        }
        while(right>=0&&nums1[right]==nums[right])
        {
            right--;
        }
        if(right<=left)return 0;
        return right-left+1;
    }
};



//O(N) time O(1) space
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        int left=0;
        int right=n-1;
        bool change=false;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<maxi)
            {
                right=i;
                change=true;
            }
            maxi=max(nums[i],maxi);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>mini)
            {
                left=i;
                change=true;
            }
            mini=min(nums[i],mini);
        }
        
        if(change==false)return (right-left+1)%n;
        return left<right?(right-left+1):0;
    }
};

