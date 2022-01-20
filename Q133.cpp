/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*>visited=vector<Node*>(101,NULL);
    Node *traverse(Node *node)
    {
        if(!node)return NULL;
        if(visited[node->val]!=NULL)return visited[node->val];
        Node *newNode=new Node(node->val);
        visited[node->val]=newNode;
        for(auto tempNode :node->neighbors)
        {
            if(visited[tempNode->val]!=NULL)
            {
                newNode->neighbors.push_back(visited[tempNode->val]);
            }
            else
            {
                Node *t=traverse(tempNode);
                newNode->neighbors.push_back(visited[tempNode->val]);
            }            
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) 
    {
        Node *ans=traverse(node);
        return ans;
    }
};
