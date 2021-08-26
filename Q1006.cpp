// Time complexity is O(n^2) and space complexity is O(1)
class Solution {
public:
    TreeNode *util(vector<int>& preorder,int start,int end)
    {
        if(start<0||start>end||end<0||end>=preorder.size())return NULL;       
        TreeNode *root=new TreeNode(preorder[start]);
        int i=start;
        for(;i<=end;i++)
        {
            if(preorder[i]>root->val)break;    
        }
        root->left=util(preorder,start+1,i-1);
        root->right=util(preorder,i,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        return util(preorder,0,preorder.size()-1);
    }
};
// We are updating root at every instance Time O(n^2) and space O(1)
class Solution {
public:
    TreeNode *build(TreeNode* &root,int x)
    {
        if(!root)return root=new TreeNode(x);
        if(root->val>x)root->left=build(root->left,x);
        else root->right=build(root->right,x);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode *root=NULL;
        for(auto x:preorder)
        {
            build(root,x);
        }
        return root;
    }
    
};
