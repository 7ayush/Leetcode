class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int x=q.size();
            vector<int>temp;
            while(x--)
            {
                Node* node=q.front();
                q.pop();
                temp.push_back(node->val);
                for(auto i:node->children)
                {
                    q.push(i);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
