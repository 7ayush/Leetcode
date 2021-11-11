class Solution {
public:
     int specialArray(vector<int>& nums) {
        int counter = 0;
        
        sort(begin(nums), end(nums));
        for(int i = 0; i < 1000; ++i){
            if(nums.end() - lower_bound(nums.begin(), nums.end(), i) == i){
                return i;
            }
        }
        return -1;
    }
};
