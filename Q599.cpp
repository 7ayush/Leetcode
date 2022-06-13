class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string,int>m1;
        vector<string>ans;  
        int maxAns=INT_MAX;
        for(int i=0;i<list1.size();i++)
        {
            m1[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++)
        {
            if(m1.count(list2[i]))
            {
                if(maxAns>m1[list2[i]]+i)
                {
                    ans.clear();
                    ans.push_back(list2[i]);
                    maxAns=m1[list2[i]]+i;
                }
                else if(maxAns==m1[list2[i]]+i)
                {
                    ans.push_back(list2[i]);
                }
            }
        }
        
        return ans;
        
    }
};
