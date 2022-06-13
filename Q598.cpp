class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mr=m;
        int mc=n;
        for(auto it:ops)
        {
            mr=min(mr,it[0]);
            mc=min(mc,it[1]);
        }
        return mr*mc;        
    }
};
