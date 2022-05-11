class Solution {
public:
    int util(TreeNode* root,int &maxi) {
        if(!root)return 0;
        if(!root->left&&!root->right)return 0;
        int l=root->left?util(root->left,maxi)+1:0;
        int r=root->right?util(root->right,maxi)+1:0;
        maxi=max(maxi,l+r);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        util(root,maxi);
        return maxi;
    }
};
