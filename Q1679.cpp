
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        map<int,int>::iterator it;
        int count=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            int key=it->first;
            int value=it->second;
            map<int,int>::iterator it1=mp.find(k-key);
            if(it1!=mp.end())
            {
                if(it1==it)
                {
                    int x=it->second/2;
                    count+=x;
                    it->second-=2*x;
                }
                else
                {
                    int x=min(it1->second,it->second);
                    count+=x;
                    it->second-=x;
                    it1->second-=x;                    
                }                
            }
        }
        return count;
    }
};



//Using hashmap

class Solution {
public: // Time/Space: O(n); O(n)
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;
        for(auto cur: nums){
            int complement = k - cur;
            if(freq[complement] > 0){ans++; freq[complement]--;}
            else freq[cur]++;
        }
        return ans;
    }
};

