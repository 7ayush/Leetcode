class Node{
    public:
    vector<Node*>vec;
    bool flag;
    Node()
    {
        vec.resize(26,NULL);
        flag=false;
    }
};
class Trie {
public:
    Node *root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(auto i:word)
        {
            if(node->vec[i-'a']==NULL)node->vec[i-'a']=new Node();                
            node=node->vec[i-'a'];
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node *node=root;
        for(char c:word)
        {
            if(node->vec[c-'a']==NULL)return false;
            node=node->vec[c-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto c:prefix)
        {
            if(node->vec[c-'a']==nullptr) return false;
            node = node->vec[c-'a'];
        }
        return true;
    }
};

