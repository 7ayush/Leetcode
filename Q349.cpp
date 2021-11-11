class Solution {
public:
    bool binarySearch(vector<int>arr, int l, int r, int x)
    {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
                return true;
            if (arr[m] < x)
                l = m + 1;

            else
                r = m - 1;
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++)
        {
             if(binarySearch(nums2,0,nums2.size()-1,nums1[i])){
                 s.insert(nums1[i]);
             }           
        }
        vector<int>ans;
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
