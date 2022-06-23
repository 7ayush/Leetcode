class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            int start=i;
            int end=nums2.size()-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums2[mid]<nums1[i])
                {
                    end=mid-1;
                }
                else
                {
                    ans=max(ans,mid-i);
                    start=mid+1;
                }
            }
        }
        return ans;
    }
};


//Two Pointers

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,ans=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]>nums2[j])i++;
            else 
            {
                ans=max(ans,j-i);
                j++;
            }
        }
        return ans;
    }
};
