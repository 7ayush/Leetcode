/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void util(TreeNode* root,int level,vector<vector<int>>&vec)
    {
        if(!root)return;
        vector<int>temp;
        if(vec.size()<=level)vec.push_back(temp);
        vec[level].push_back(root->val);
        if(root->left)util(root->left,level+1,vec);
        if(root->right)util(root->right,level+1,vec);
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>vec;
        util(root,0,vec);
        return vec;
    }
};
