class Solution {
public:
    void leftLimit(TreeNode *root,int left,int *maxLeft)
    {
        if(!root)return;
        if(left>*maxLeft)*maxLeft=left;
        leftLimit(root->left,left+1,maxLeft);
        leftLimit(root->right,left-1,maxLeft);
    }
    void rightLimit(TreeNode *root,int right,int *maxRight)
    {
        if(!root)return;
        if(right>*maxRight)*maxRight=right;
        rightLimit(root->right,right+1,maxRight);
        rightLimit(root->left,right-1,maxRight);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int l=0,r=0;
        leftLimit(root,0,&l);
        rightLimit(root,0,&r);
        vector<vector<int>>ans(l+r+1);
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int x=q.size();
            map<int,vector<int>>mp;
            while(x--)
            {
                auto x=q.front();
                q.pop();
                mp[x.second+l].push_back(x.first->val);
                if(x.first->left)q.push({x.first->left,x.second-1});
                if(x.first->right)q.push({x.first->right,x.second+1});
            }
            for(auto &i:mp)sort(i.second.begin(),i.second.end());
            for(auto i:mp)ans[i.first].insert(ans[i.first].end(),i.second.begin(),i.second.end());
        }
        return ans;        
    }
};
