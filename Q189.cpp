//Rotate everytime O(N*K)
class Solution {
public:
    void rotateOnce(vector<int>&nums)
    {
        int n=nums.size();
        int temp=nums[n-1];        
        for(int i=n-1;i>0;i--)
        {
            nums[i]=nums[i-1];
        }
        nums[0]=temp;
    }
    void rotate(vector<int>& nums, int k) 
    {
        for(int i=0;i<k;i++)
        {
            rotateOnce(nums);
        }
    }
};
// O(N) time O(N) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        k=k%n;
        vector<int>temp;
        for(int i=n-k;i<n;i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i=n-1;i-k>=0;i--)
        {
            nums[i]=nums[i-k];
        }
        for(int i=0;i<k;i++)
        {
            nums[i]=temp[i];
        }
    }
};


// O(N) time O(1) space Reversing 3 times
class Solution {
public:
    void reverse(vector<int>&nums,int low,int high)
    {
        while(high>low)
        {
            swap(nums[high],nums[low]);
            high--;
            low++;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        k=k%nums.size();
        int i=0,j=nums.size()-1;
        reverse(nums,i,j-k);
        reverse(nums,j-k+1,j);
        reverse(nums,i,j);
    }
};
