/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    int maxDepth(Node* root) {
        queue<pair<Node*,int>>q;
        int maxSize=0;
        if(!root)return 0;
        q.push({root,1});
        while(!q.empty())
        {
            Node *curr=q.front().first;
            int height=q.front().second;
            q.pop();
            
            for(Node *child:curr->children)
            {
                q.push({child,height+1});
            }
            maxSize=max(maxSize,height);
        }
        return maxSize;
    }
};
