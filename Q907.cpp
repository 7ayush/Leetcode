//Brute Force TLE
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long int sum=0;
        int exp=1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            int mini=arr[i];
            for(int j=i;j<arr.size();j++)
            {
                mini=min(mini,arr[j]);
                sum=(sum+mini)%exp;
            }
        }
        return sum;
    }
};
