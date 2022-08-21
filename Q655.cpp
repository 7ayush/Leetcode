class Solution {
public:
    int height(TreeNode *root)
    {
        if(!root)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void fill(TreeNode *root,int i,int start,int end,vector<vector<string>>&vec)
    {
        if(!root)return;
        int mid=(start+end)/2;
        vec[i][mid]=to_string(root->val);
        fill(root->left,i+1,start,mid-1,vec);
        fill(root->right,i+1,mid+1,end,vec);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root)return {};
        int h=height(root);
        vector<vector<string>>vec(h,vector<string>(pow(2,h)-1,""));
        fill(root,0,0,vec[0].size()-1,vec);
        return vec;
    }
};
