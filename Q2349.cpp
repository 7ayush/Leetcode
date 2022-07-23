class NumberContainers {
public:
    unordered_map<int,int>mp;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp1;
    NumberContainers() {}
    
    void change(int index, int number) 
    {
        if(mp.find(index)!=mp.end())//updation
        {
            if(mp[index]==number)return;
            int val=mp[index];
            vector<int>vals;
            while(!mp1[val].empty())
            {
                int x=mp1[val].top();
                mp1[val].pop();
                if(x!=index)vals.push_back(x);
                else break;
            }
            for(auto i:vals)mp1[val].push(i);
            if(mp1[val].empty())mp1.erase(val);
        }
        mp[index]=number;
        mp1[number].push(index);
    }
    
    int find(int number) {
        if(mp1.find(number)!=mp1.end())
        {
            return mp1[number].top();
        }
        return -1;
    }
};

