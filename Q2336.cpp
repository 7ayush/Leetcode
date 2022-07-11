class SmallestInfiniteSet {
public:
    set<int>s;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int x=1;
        for(int i:s)
        {
            if(x!=i)
            {
                s.insert(x);    
                return x;
            }
            else 
                x++;
        }
        s.insert(x);
        return x;
        
    }
    
    void addBack(int num) {
        if(s.find(num)!=s.end())
        {
            s.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
