// Iterative Solution for Inorder traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>vec;
        stack<TreeNode*>s;
        TreeNode *curr=root;
        while(curr||!s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            vec.push_back(curr->val);
            curr=curr->right;            
        }            
        return vec;
    }
};

//Recursive Approach
class Solution {
public:
    void recursive(TreeNode* root, vector<int>&vec)
    {
        if(root)
        {
            recursive(root->left,vec);
            if(root) vec.push_back(root->val);
            recursive(root->right,vec);   
        }
        
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>vec;
        recursive(root,vec);
        return vec;
    }
};
