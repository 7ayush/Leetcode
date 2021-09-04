//Sorting Solution O(nlogn)
class Solution {
public:
    static bool compare(int &a,int &b)
    {
        return abs(a)<abs(b);
    }
    vector<int> sortedSquares(vector<int>& nums) 
    {
         sort(nums.begin(),nums.end(),compare);
        vector<int>ans;
         for(int i=0;i<nums.size();i++)       
         {
             ans.push_back(nums[i]*nums[i]);
         }
        return ans;
    }
};

//Two Pointer solution O(N) and O(N) space
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n=nums.size();
        int i=0,j=n-1;        
        vector<int>ans(n);
        int k=n-1;
        while(i<=j&&k>=0)
        {
            if(abs(nums[i])>=abs(nums[j]))
            {
                ans[k]=nums[i]*nums[i];
                i++;
            }
            else
            {
                ans[k]=nums[j]*nums[j]; 
                j--;
            }
            k--;
        }
        return ans;
        
    }
};
//[