// Updating the tree to have the path from root to it and then finding the sum of all the root nodes
class Solution {
public: 
    void util(TreeNode *root)
    {
        if(!root)return;
        if(root->left)root->left->val=root->val*10+root->left->val;
        if(root->right)root->right->val=root->val*10+root->right->val;
        util(root->left);
        util(root->right);
    }
    void findSum(TreeNode *root,int *ans)
    {
        if(!root)return;
        findSum(root->left,ans);
        findSum(root->right,ans);
        if(!root->left&&!root->right)*ans=*ans+root->val;
        
    }
        
    int sumNumbers(TreeNode* root) {
        util(root);
        int ans=0;
        findSum(root,&ans);
        return ans;
    }
};


// Finding current path value for each node and then adding path to sum upon reaching the leaf node
class Solution {
public:
    void util(TreeNode *root,int path,int &sum)
    {
        if(!root)return;
        path=path*10+root->val;
        util(root->left,path,sum);
        util(root->right,path,sum);
        if(!root->left&&!root->right)sum+=path;
        
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        util(root,0,sum);
        return sum;
    }
};
