class Solution {
public:
    bool equalFrequency(string word) {
        vector<int>hash(26,0);
        for(char c:word) hash[c-'a']++;
        sort(hash.begin(),hash.end(),greater<int>());
        map<int,int>mp;
        for(auto i:hash)if(i!=0)mp[i]++;

        if(mp.size()>2)return false;

        if(mp.size()==1){
            if(mp.find(1)!=mp.end()||mp.begin()->second==1)
                return true;
            else 
                return false;
        }
        
        auto it=mp.begin();
        auto nxt=next(it);
        if((nxt->first-it->first==1&&nxt->second==1)|| (it->first==1&&it->second==1) ){
            return true;
        }
        return false;
    }
};
