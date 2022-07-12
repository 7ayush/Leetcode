class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);        
        while(!q.empty())
        {
            int n=q.size();
            bool flag=0;
            while(n--)
            {
                TreeNode *t=q.front();
                q.pop();
                if(!flag)
                {
                    ans.push_back(t->val);                    
                    flag=true;
                }
                if(t->right)q.push(t->right);
                if(t->left)q.push(t->left);                
            }
        }
        return ans;
    }
};
