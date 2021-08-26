//We use a vector of {nums}+{nums} so that the problem of cycle is handled
class Solution {
public:
    vector<int>getVector(vector<int>nums2)
    {
        stack<int>s;
        vector<int>vec2(nums2.size());
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(i==nums2.size()-1)
            {                
                vec2[i]=-1;
            }
            else
            {
                while(!s.empty()&&s.top()<=nums2[i])s.pop();
                
                if(s.empty())vec2[i]=-1;
                else vec2[i]=s.top();                
            }            
            s.push(nums2[i]);
        }    
        return vec2;
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        vector<int>vec(2*nums.size());
        for(int i=0;i<nums.size();i++)
        {
            vec[i]=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            vec[i+nums.size()]=nums[i];
        }
        vector<int>ans=getVector(vec);
        ans.resize(nums.size());
        return ans;
    }
}};
