
class Solution {
public:
    void util(Node *root)
    {
        if(!root)return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int x=q.size();
            int i=0;
            while(i<x)
            {
                Node *temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                if(i<x-1)temp->next=q.front();
                else
                {
                    temp->next=NULL;
                }
                i++;
            }
            
        }
        
    }
    Node* connect(Node* root) {
        util(root);
        return root;
    }
};
