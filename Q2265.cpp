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
    pair<int,int> iterate(TreeNode *root,int *ans)
    {
        if(!root)return {0,0};
        pair<int,int>left=iterate(root->left,ans);
        pair<int,int>right=iterate(root->right,ans);
        int count=left.first+right.first+1;
        int sum=left.second+right.second+root->val;
        if(root->val==sum/count){
            *ans=*ans+1;
        }
        return {count,sum};

    }
    int averageOfSubtree(TreeNode* root) {
       int ans=0; 
        iterate(root,&ans);
        return ans;
    }
};
