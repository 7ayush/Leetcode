class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int len=strs[0].size();
        for(int i=0;i<len;i++)
        {
            bool flag=false;
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i]<strs[j-1][i])
                {                    
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                ans++;
            }
        }
        return ans;
    }
};
