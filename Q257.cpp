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
    void util(TreeNode *root,vector<string>&s,string str)
    {
        if(!root)return;        
        if(!root->left&&!root->right)
        {
            str+=to_string(root->val);    
            s.push_back(str);
            return;
        }
        str+=to_string(root->val)+"->";
        util(root->left,s,str);
        util(root->right,s,str);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>s;
        string str="";
        util(root,s,str);
        return s;
        
    }
};
