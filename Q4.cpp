class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        int finalArray[n+m];
        int i=0,j=0,k=0;
        while(i<m && j<n) {
            if(nums1[i]<nums2[j]) {
                finalArray[k++] = nums1[i++];
            }
            else {
                finalArray[k++] = nums2[j++];
            }
        }
        if(i<m) {
            while(i<m) 
                finalArray[k++] = nums1[i++];
        }
        if(j<n) {
            while(j<n)
                finalArray[k++] = nums2[j++];
        }
        n = n+m;
        if(n%2==1) 
            return finalArray[((n+1)/2)-1];
        else return ((float)finalArray[(n/2)-1]+(float)finalArray[(n/2)])/2;
    }

};

//Binary Search Method
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        int m=nums1.size();
        int n=nums2.size();
        
        int low=0;
        int high=m;
        
        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=(m+n+1)/2-cut1;
            
            int left1=cut1==0?INT_MIN:nums1[cut1-1];
            int left2=cut2==0?INT_MIN:nums2[cut2-1];
            
            int right1=cut1==m?INT_MAX:nums1[cut1];
            int right2=cut2==n?INT_MAX:nums2[cut2];
            
            if(left1<=right2&&left2<=right1)
            {
                if((m+n)%2==0)return (max(left1,left2)+min(right1,right2))/2.0;
                else return max(left1,left2);
            }
            else if(left1>right2)
            {
                high=cut1-1;
            }
            else low=cut1+1;            
        }
        return 0.0;
    }

};
