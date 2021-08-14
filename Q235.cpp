//This is bruteforce, we are storing the path to both nodes from root and then finding LCA from those 2 paths

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void pathToNode(TreeNode *root,TreeNode *node,vector<TreeNode*>&vec)
    {
        if(!root)return;
        vec.push_back(root);
        if(root->val==node->val)return;
        else if(root->val<node->val)pathToNode(root->right,node,vec);
        else pathToNode(root->left,node,vec);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*>a;    
        pathToNode(root,p,a);
        vector<TreeNode*>b;
        pathToNode(root,q,b);
        int mini=min(a.size(),b.size());
        TreeNode *eq;
        for(int i=0;i<mini;i++)
        {
            if(a[i]==b[i])eq=a[i];
            else break;
        }
        return eq;
    }
};


// We will find the nodes by iterating in the entire tree and then returning LCA upto the root node; this code will also work on a Normal Binary tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)return NULL;
        if(root==p||root==q)return root;
        TreeNode *l=lowestCommonAncestor(root->left,p,q);
        TreeNode *r=lowestCommonAncestor(root->right,p,q);
        if(l&&r)return root;
        if(!l&&!r)return NULL;
        return l?l:r;
        
    }
};

// Optimised code for binary search tree. The idea is simple, LCA will have one child smaller than it and other one bigger than it
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {   
        if(!root)return NULL;
        if(root->val < p->val && root->val<q->val)
             return lowestCommonAncestor(root->right,p,q);
        else if(root->val > p->val && root->val > q->val)
             return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};
