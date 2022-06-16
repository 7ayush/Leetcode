// Recursive 
hclass Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        int self = root->val;
        if(root->left) self += (rob(root->left->left) + rob(root->left->right));
        if(root->right) self += (rob(root->right->left) + rob(root->right->right));
        int nself = (rob(root->left) + rob(root->right));
        return max(self ,nself);    
    }
};

//After Memoization
class Solution {
public:
    unordered_map<TreeNode*,int> m;
    int rob(TreeNode* root) {
        if(m.count(root)) return m[root];
        if(!root) return 0;
        int self = root->val;
        if(root->left) self += (rob(root->left->left) + rob(root->left->right));
        if(root->right) self += (rob(root->right->left) + rob(root->right->right));
        int nself = (rob(root->left) + rob(root->right));
        m[root] = max(self ,nself);
        return m[root];
    }
};
