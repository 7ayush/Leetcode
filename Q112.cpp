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
    bool util(TreeNode *root,int sum,int target)
    {
        if(!root)
        {           
           return false;
        }
        sum+=root->val;
        if(!root->left&&!root->right)
        {
            if(sum==target)return true;
            return false;
        }
        return util(root->left,sum,target)||util(root->right,sum,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if(!root)return false;
       return util(root,0,targetSum);
       
    }
};
