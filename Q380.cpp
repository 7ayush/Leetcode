class RandomizedSet {
public:
    set<int>myset;
    RandomizedSet() {
        cout << "Set initialized";
    }
    
    bool insert(int val) {
        if (myset.find(val) == myset.end())
        {
            myset.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        
        if (myset.find(val) == myset.end())            
            return false;        
        
        auto it = myset.find(val);
        myset.erase(it);                    
        return true;
    }
    
    int getRandom() {
        int size = myset.size();
        int random = rand() % size;            
        
        auto it = myset.begin();
        std::advance(it, random);
        
        return *it;
    }
};

