class Solution {
public:
    void fill(TreeNode *root,vector<int>&v)
    {
        if(!root)return;
        if(!root->left&&!root->right)v.push_back(root->val);
        fill(root->left,v);
        fill(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        fill(root1,v1);
        fill(root2,v2);
        if(v1.size()!=v2.size())return false;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])return false;
        }
        return true;
    }
};
