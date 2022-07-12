//Kadane on every index TLE
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.end(),nums.begin(),nums.end());
        int currSum=0;
        int maxSum=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            currSum=0;
            for(int j=0;j<n;j++)
            {
                currSum+=nums[i+j];
                if(maxSum<currSum)maxSum=currSum;            
                if(currSum<0)currSum=0;
            }            
        }
        return maxSum;
    }
};


// Either the subarray will lie in the middle or on the both corners 
// So first we calculate using normal kadane algo
// And after that we invert the elements and apply kadane.
// The negative of this answer will give us most minimum subarray sum of middle elements. Subtracting this value from totalSum will give us circular max subarray sum
// Choose between normal and this calculated value
class Solution {
public:
    int kadane(vector<int> &nums)
    {
        int maxEnding = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxEnding = max(nums[i], maxEnding + nums[i]);
            res = max(maxEnding, res);
        }
        return res;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        int normalSub = kadane(nums);

        if (normalSub < 0)
            return normalSub;

        int tot_sum = 0;
        for (int i = 0; i < n; i++)
        {
            tot_sum += nums[i];
            nums[i] = -1 * nums[i];

        }
        int maxCircular = tot_sum + kadane(nums);
        return max(normalSub, maxCircular);
    }
};
