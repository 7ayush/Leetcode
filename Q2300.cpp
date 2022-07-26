class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<spells.size();i++)
        {
            
            long long x=(success/spells[i]);
            if(success%spells[i])x++;
            int idx=potions.end()-lower_bound(potions.begin(),potions.end(),x);
             ans.push_back(idx);
        }
        return ans;      
    }
};
