class TimeMap {
public:
    unordered_map<string,map<int,string>>mp;
    TimeMap() {
        
    }
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        auto it=mp.find(key);
        if(it==mp.end())return "";

        auto it1=it->second.lower_bound(timestamp);
        if(it1!=it->second.end()&&it1->first==timestamp){
            return it1->second;
        }
        auto it2=prev(it1);
        if(it2!=it->second.end()&&it2->first<timestamp){
            return it2->second;
        }            
        else
        {
            return "";
        }
    }
};
