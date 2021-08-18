// BruteForce Solution storing inorder traversal and then returning the minimum consecutive difference 
class Solution {
public:
    void util(TreeNode* root,vector<int>&vec)
    {
        if(root)
        {
            util(root->left,vec);
            vec.push_back(root->val);
            util(root->right,vec);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int minimum=INT_MAX;
        vector<int>vec;
        util(root,vec);
        for(int i=0;i<vec.size()-1;i++)
        {
            int diff=vec[i+1]-vec[i];
            if(diff<minimum)minimum=diff;
        }
        return minimum;
    }
};
