typedef long long ll;
class Solution {
public:
    ll mod=1e9+7;
    int concatenatedBinary(int n) {
        ll ans=0;
        ll y=1;
        while(n){
            int x=n;
            while(x){
                int mask=(x&1);
                ans=(ans+mask*y)%mod;
                x>>=1;
                y=(y*2)%mod;
            }
            n--;
        }
        return ans;
    }
};
