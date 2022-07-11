class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int k = k1 + k2;
        map<int, int, greater<int>>mp;
        for (int i = 0; i < nums1.size(); ++i) 
        {
            int x=abs(nums1[i] - nums2[i]);
            if(x>0)mp[x]++;
        }
        mp[0]=0;
        while(k)
        {
            auto largest=mp.begin();
            
            map<int,int>::iterator nxt=next(largest);
            int val=largest->first;
            if(val==0)break;
            int freq=largest->second;
            int dec=k/freq;
            int remain=k%freq;
            int diff= val- nxt->first;
            
            if(dec>=diff)
            {
                dec=(largest->first-nxt->first)*largest->second;
                k-=dec;
                mp[nxt->first]+=freq;
                mp.erase(largest);
            }
            else
            {
                mp.erase(largest);
                mp[val-dec]+=freq-remain;
                mp[val-dec-1]+=remain;
                k=0;
            }            
        }  
        long long result = 0;
        for (const auto& [diff, freq] : mp) {
            result += long(diff) * long(diff) * freq;
        }
        return result;
    }
};
