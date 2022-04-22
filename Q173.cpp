class BSTIterator {
public:
    stack<int>s;
    BSTIterator(TreeNode* root) {
        inorder(root);
        s.push(-1);
    }
    
    int next() {
        s.pop();
        return s.top();
    }
    
    bool hasNext() {
        return s.size()>=2;
    }
    void inorder(TreeNode *root)
    {
        if(!root)return;
        inorder(root->right);
        s.push(root->val);
        inorder(root->left);
    }
};

