class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>ans;        
        if(arr.size()<4)return ans;
        set<vector<int>>unique;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int l=j+1;
                int r=arr.size()-1;
                bool flag=true;
                
                while(l<r&&r<arr.size()&&flag)
                {
                    
                    if(arr[i]/10+arr[j]+arr[l]/10>=INT_MAX/10||arr[i]/10+arr[j]+arr[l]/10<=INT_MIN/10)
                    {
                        l++;r--;
                        continue;                        
                    }
                    int s=arr[i]+arr[j]+arr[l]+arr[r];
                    if(s==k)
                    {
                        vector<int>temp{arr[i],arr[j],arr[l],arr[r]};                        
                        unique.insert(temp);
                        l++;r--;
                    }
                    else if(s<k)
                    {
                        l++;
                    }
                    else 
                    {
                        r--;
                    }
                }
            }
        }
        for(vector<int>vec:unique)
        {
            ans.push_back(vec);
        }
        return ans;
        
    }
};
