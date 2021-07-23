// O(N) time and O(1) space
// we will be iterating in the reverse order and putting the biggest element in the end
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int last=m+n-1;
        if(m==0){
            nums1=nums2;
            return;
        }
        if(n==0)
        {
            return;
        }
        int i=m-1,j=n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[last--]=nums1[i--];
            }
            else
            {
                nums1[last--]=nums2[j--];
            }
        }
        while(i>=0)
        {
            nums1[last--]=nums1[i--];
        }
        while(j>=0)
        {
            nums1[last--]=nums2[j--];
        }
        
    }
};
