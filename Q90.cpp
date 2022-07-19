class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        int len=nums.size();
        int power=pow(2,len);
        sort(nums.begin(),nums.end());
        for(int i=0;i<power;i++)
        {
            vector<int>temp;
            for(int j=0;j<len;j++)
            {
                if((i>>j)&1){
                    temp.push_back(nums[j]);
                }
            }
            s.insert(temp);
        }
        vector<vector<int>>vec;
        for(auto i:s)vec.push_back(i);
        return vec;
    }
};
