//Same as house robber we cannot choose consecutive 2 values
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>ans(10001,0);
        for(auto i:nums)ans[i]+=i;       
        ans[2]+=ans[0];
        for(int i=3;i<ans.size();i++)
        {
            ans[i]+=max(ans[i-2],ans[i-3]);
        }
        return max(ans[ans.size()-1],ans[ans.size()-2]);
    }
};

// Maintain take and skip variable for iterating on hash*freq array 1d
// if we are taking current element then we are skipping the prev element
// if we are skipping the current element we are taking the max of prev element's take and skip value because we need to make max value answer
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};
