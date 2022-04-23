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
    void findSum(TreeNode *root,int *sum,int prev)
    {
        if(!root)return ;
        prev=prev*2+root->val;
        if(!root->left&&!root->right)*sum=*sum+prev;
        findSum(root->left,sum,prev);
        findSum(root->right,sum,prev);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        findSum(root,&sum,0);
        return sum;
    }
};
