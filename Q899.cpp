class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K>=2){
            sort(S.begin(),S.end());
            return S;
        }
        string ans = S.substr(1) + S.substr(0,1);
        string mini = S;
        while(ans!=S){
            // cout<<ans<<endl;
            mini = min(ans,mini);
            ans = ans.substr(1) + ans.substr(0,1);
        }
        return mini;
    }
};

