class Solution {
public:
    int height(TreeNode *root)
    {
        if(!root)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void level(TreeNode *root,int l,vector<vector<int>>&vec)
    {
        if(!root)return;
        vec[l-1].push_back(root->val);
        level(root->left,l+1,vec);
        level(root->right,l+1,vec);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        int h=height(root);
        vector<vector<int>>levels(h);
        level(root,1,levels);
        for(int i=0;i<levels.size();i++)
        {
            double avg=0.0;
            for(int j=0;j<levels[i].size();j++)
            {
                avg+=levels[i][j];
            }
            avg=avg/levels[i].size();
            ans.push_back(avg);
        }
        return ans;
    }
};
