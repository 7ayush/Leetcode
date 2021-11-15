// Using map and counting frequencies
class Solution {
public:
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        vector<int>ans;
        for(auto i:nums1)
        {
            if(!m.count(i))
            {
                m.insert({i,1});
            }
            else
            {
                m[i]++;
            }
        }
        for(auto i:nums2)
        {
            if(m[i]!=0){
                ans.push_back(i);
                m[i]--;
            }
        }
        
        return ans;
    }
};
