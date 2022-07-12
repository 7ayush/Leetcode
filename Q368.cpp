class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i].push_back(nums[i]);
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]%nums[i]==0)    
                {
                    if(ans[j].size()<=ans[i].size())
                    {
                        ans[j]=ans[i];
                        ans[j].push_back(nums[j]);
                    }
                }
            }            
        }
        int maxAns=0;
        vector<int> last={};
        for(auto i:ans)
        {
            if(i.size()>maxAns)
            {
                maxAns=i.size();
                last=i;
            }
        }
        return last;
    }
};


//LIS 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans(n,1);
        int maxAns=1;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]%nums[i]==0)    
                {
                    if(ans[j]<=ans[i])
                    {
                        ans[j]=ans[i]+1;
                        maxAns=max(maxAns,ans[j]);
                    }
                }
            }            
        }
        // for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        // cout<<endl;
        cout<<maxAns;
        vector<int> last={};
        int prev=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(ans[i]==maxAns&&prev%nums[i]==0)
            {
                last.push_back(nums[i]);
                maxAns--;
                prev=nums[i];
            }
        }
        sort(last.begin(),last.end());
        return last;
    }
};
