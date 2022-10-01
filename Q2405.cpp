class Solution {
public:
    int partitionString(string s) {
        if(s.size()==0)return 0;
        int count=1;
        int n=s.size();
        vector<int>hash(26,0);
        for(int i=0;i<n;i++)
        {
            if(hash[s[i]-'a']>0)
            {
                hash=vector<int>(26,0);
                hash[s[i]-'a']=1;
                count++;
            }
            else
            {
                hash[s[i]-'a']++;
            }
        }
        return count;
    }
};
