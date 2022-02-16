class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid-1>=start&&arr[mid-1]==arr[mid])
            {
                int leftLength=mid-start+1;
                int rightLength=end-start;
                if(leftLength&1)
                {
                    end=mid;
                }
                else
                {
                    start=mid+1;
                }
                
            }
            else if(mid+1<=end&&arr[mid+1]==arr[mid])
            {
                int leftLength=mid-start;
                int rightLength=end-mid+1;
                if(rightLength&1)
                {
                    start=mid;
                }
                else
                {
                    end=mid-1;
                }
            }
            else
            {
                return arr[mid];
            }            
        }
        return -1;
    }
};
