class Bucket {
private:
    forward_list<int> container;
public:    
    void insert(int key) {
        if (std::find(container.begin(), container.end(), key) == container.end()) 
            container.push_front(key);
    }
    
    void erase(int key) {
        container.remove(key);
    }
    
    bool exists(int key) {
        return std::find(container.begin(), container.end(), key) != container.end();
    }
    
};

class MyHashSet {
private:
    int keyRange = 769;
    Bucket bucketArray[769];

public:
    void add(int key) {
        bucketArray[key % keyRange].insert(key);
    }
    
    void remove(int key) {
        bucketArray[key % keyRange].erase(key);
    }
    
    bool contains(int key) {
        return bucketArray[key % keyRange].exists(key);
    }
};



class MyHashSet {
public:
    int MOD;
    vector<vector<int>> stuff;
    MyHashSet() {
        MOD = 1000;
        stuff.resize(MOD);
    }
    
    void add(int key) {
        int myKey = key % MOD;
        for(int x : stuff[myKey]) {
            if(x == key) return;
        }
        stuff[myKey].push_back(key);
    }
    
    void remove(int key) {
        int myKey = key % MOD;
        auto it = find(stuff[myKey].begin(), stuff[myKey].end(), key);
        if(it != stuff[myKey].end()) {
            stuff[myKey].erase(it);
        }       
    }
    
    bool contains(int key) {
        int myKey = key % MOD;
        auto it = find (stuff[myKey].begin(), stuff[myKey].end(), key);
        return it != stuff[myKey].end();

    }
};
