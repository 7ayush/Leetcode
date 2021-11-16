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

