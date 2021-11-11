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
