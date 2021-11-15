class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int no=1,cnt=0;
        set<int>s;
        int n=arr.size();
        for(int i=0;i<n;i++)
        s.insert(arr[i]);

           while(cnt!=k)
           {
               if(!s.count(no))
                   cnt++;
               no++;
           }
            return no-1;
        }
    

};
// 2,3,4,7,11
// 0,1,2,3 ,4
// 1 1 1 3  6
// Using binary Search and using an auxillary array to store difference of array
class Solution {
public:
    int binarySearch(vector<int>arr,int k)
    {
        int l=0,r=arr.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid]<k)
            {
                if(mid+1>r||arr[mid+1]>=k)
                    return mid;
                else
                    l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1;
    }
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>diff;
        for(int i=0;i<arr.size();i++)
        {
            diff.push_back(arr[i]-i-1);
        }
        int ans=binarySearch(diff,k);
        if(diff[0]>=k)return k;
        return arr[ans]+k-diff[ans];        
    }
};
