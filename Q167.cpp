class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int>ans;
        int n=numbers.size();
        int i=0,j=n-1;
        while(i<j)
        {
            int sum=numbers[i]+numbers[j];
            if(sum==target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(sum<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        if(ans.empty())ans.push_back(-1);
        return ans;
    }
};
