class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        set<double>s;
        while(i<j)
        {
            double x=(nums[i]+nums[j])/2.0;
            s.insert(x);
            i++;j--;
        }
        return s.size();
        
    }
};
