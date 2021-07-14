#include "bits.h"

bool compare(pair<int,int>&a,pair<int,int>&b)
{
    return a.first<b.first;
}
class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<pair<int,int>>pos;
        for(int i=0;i<nums.size();i++)
        {
            pos.push_back(make_pair(nums[i],i));
        }        
        sort(pos.begin(),pos.end(),compare);
        for(int i=0;i<nums.size();i++)
        {
            cout<<"("<<pos[i].first<<","<<pos[i].second<<") ";
        }
        int i=0;
        int j=pos.size()-1;
        int sum=pos[i].first+pos[j].first;
        while(sum!=target&&i<j)
        {
            if(sum<target)
            {
                i++;                    
            }
            else 
            {
                j--;
            }
            sum=pos[i].first+pos[j].first;
        }
        while(pos[j-1].first==pos[j].first&&j-1!=i)
        {
            j--;
        }
        vector<int>ans;
        ans.push_back(pos[i].second);
        ans.push_back(pos[j].second);
        return ans;
        
    }
};