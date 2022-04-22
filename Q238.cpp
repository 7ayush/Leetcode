class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
       long long int prod=1;
       int cnt=count(nums.begin(),nums.end(),0);
       if(cnt>1)
       {
            vector<int>ans(nums.size(),0);
            return ans;
       }
       vector<int>ans;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]!=0)
            prod*=nums[i];
       }
       for(int i=0;i<nums.size();i++)
       {
           if(cnt==1)
           {
               if(nums[i]!=0)
               {
                   ans.push_back(0);
               }
               else
               {
                   ans.push_back(prod);
               }
           }
           else
           {
                ans.push_back(prod/nums[i]);
           }
           
           
       }
       return ans;
       
        //code here        
    }
};
