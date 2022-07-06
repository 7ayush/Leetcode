class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int mini=min_element(nums.begin(),nums.end())-nums.begin();
        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
        
        if(mini>maxi)swap(mini,maxi);

        int a=mini;
        int b=maxi-mini-1;
        int c=nums.size()-maxi-1;
        return min(min(a+b,b+c),c+a)+2;
        
    }
};
