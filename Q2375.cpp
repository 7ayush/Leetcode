class Solution {
public:
    string smallestNumber(string p) {
        int n = p.length();
        string ans = "";
        for(int i = 1; i <= n + 1; ++i)
            ans += (char)(i + '0');
        for(int i = 0; i < n; ++i){
            if(p[i] == 'D'){
                int j = i;
                while(i < n && p[i] == 'D') i++;
                reverse(ans.begin() + j, ans.begin() + i + 1);
            }
        }
        return ans;
    }
};
