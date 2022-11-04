class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x=pref[0];
        vector<int>ans;
        int y;
        ans.push_back(pref[0]);
        for(int i=1;i<pref.size();i++)
        {
            y=x;
            x=pref[i]^x;            
            ans.push_back(x);
            x=x^y;
        }
        return ans;
    }
};
