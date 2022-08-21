class Solution {
public:
    void fill(TreeNode *root,unordered_map<int,vector<int>>&mp)
    {
        if(!root)return;
        if(root->left)
        {
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        fill(root->left,mp);
        fill(root->right,mp);
    }
    int dfs(int curr,unordered_map<int,vector<int>>&mp,unordered_set<int>&vis)
    {
        int ans=0;
        vis.insert(curr);
        for(auto i:mp[curr])
        {
            if(vis.find(i)==vis.end())
            {
                ans=max(ans,1+dfs(i,mp,vis));
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>mp;
        fill(root,mp);
        unordered_set<int>vis;
        return dfs(start,mp,vis);
        
    }
};
