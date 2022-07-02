class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        int size=0;
        while(!q.empty())
        {
            int n=q.size();
            ans.push_back({});
            while(n--)
            {
                TreeNode *temp=q.front();
                q.pop();
                ans[size].push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            size++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
