class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        for(int i=1;i<arr.size();i++)arr[i]+=arr[i-1];
        
        for(int i=1;i<=arr.size();i+=2)
        {
            for(int j=i-1;j<arr.size();j++)
            {
                int k=j-i;
                if(k==-1)k=arr[j];
                else k=arr[j]-arr[k];
                sum+=k;
            }
        }
        return sum;
    }
};
