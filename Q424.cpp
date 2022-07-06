class Solution {
    public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, maxi = 0;
        unordered_map<char,int>mp;
        int ans = -1;
        while(j < n)
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            cout<<i<<" "<<j<<endl;
            if((j-i+1) - maxi > k){
                mp[s[i]]--;
                i++;
            }
            else 
                ans = max(ans, (j-i+1));
            j++;   
        }
        return ans;
    }
};
