//In this question we will be first finding the NGR element for nums2 array and store it all in another vector of same size.
// After that we will iterate over all the elements in the nums1 array and then we will find the corresponding element in nums2 array and corresponding to the location we will fetch the NGR and store it in vec1 array
class Solution {
public:
    int find(int key,vector<int>nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(key==nums[i])return i;
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int>s;
        vector<int>vec1(nums1.size());
        vector<int>vec2(nums2.size());
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(i==nums2.size()-1)
            {                
                vec2[i]=-1;
            }
            else
            {
                while(!s.empty()&&s.top()<nums2[i])s.pop();
                
                if(s.empty())vec2[i]=-1;
                else vec2[i]=s.top();                
            }            
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            int x=find(nums1[i],nums2);
            if(x==-1)vec1[i]=-1;
            else
            {
                vec1[i]=vec2[x];
            }
        }
        return vec1;
        
    }
};



//In this question we will be first finding the NGR element for nums2 array and storing the nums2 element and NGR in a map
// After that we will iterate over all the elements in the nums1 array and then we will find the corresponding element in map and then save that element in vec1 and then return vec1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int>s;
        vector<int>vec1(nums1.size());
        map<int,int>m;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(i==nums2.size()-1)
            {                
                m[nums2[i]]=-1;
            }
            else
            {
                while(!s.empty()&&s.top()<nums2[i])s.pop();
                
                if(s.empty())m[nums2[i]]=-1;
                else m[nums2[i]]=s.top();                
            }            
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            map<int,int>::iterator it=m.find(nums1[i]);
            vec1[i]=(*it).second;
        }
        return vec1;
        
    }
};
