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

// Time -> O(N)
// Space-> size of stack O(N)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        //if both are NULL
        if(!p&&!q)return true;
        //if only one is NULL
        if(!p||!q)return false;
        //if both are not null and value is not equal
        if(p->val!=q->val)return false;
        
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        
        
    }
};
