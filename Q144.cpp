//Preorder traversal Node left right

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
    void recursive(TreeNode *root,vector<int>&vec)
    {
        if(root)
        {
            vec.push_back(root->val);
            recursive(root->left,vec);
            recursive(root->right,vec);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>vec;
        recursive(root,vec);
        return vec;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {        
        vector<int>vec;
        if(!root)return vec;
        stack<TreeNode*>s;
        s.push(root);
        TreeNode *curr;
        while(!s.empty())
        {
            
            curr=s.top();
            s.pop();
            vec.push_back(curr->val);            
            if(curr->right)s.push(curr->right);         
            if(curr->left)s.push(curr->left);
               
        }
        return vec;
    }
};
