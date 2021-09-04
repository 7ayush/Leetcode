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

class Solution {  
    TreeNode *getNewnode(int val)
    {
        TreeNode *newnode = new TreeNode;
        newnode->val = val;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    
    int construct_BST(vector<int> &preorder,int n,int pos,TreeNode *curr,int left,int right)
    {
        if(pos==n || preorder[pos]<left || preorder[pos]>right) //Boundary case
            return pos;
        
        if(preorder[pos]<curr->val)     //Insert in left-subtree
        {
            curr->left = getNewnode(preorder[pos]);
            pos += 1;
            pos = construct_BST(preorder,n,pos,curr->left,left,curr->val-1);
        }
        
        if(pos==n || preorder[pos]<left || preorder[pos]>right)
            return pos;
        
        //Insert in right-subtree
        curr->right = getNewnode(preorder[pos]);
        pos += 1;
        pos = construct_BST(preorder,n,pos,curr->right,curr->val+1,right);
        return pos;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();
        if(n==0)
            return NULL;
        
        TreeNode *root = getNewnode(preorder[0]);
        if(n==1)
            return root;

        construct_BST(preorder,n,1,root,INT_MIN,INT_MAX);
        return root;
    }
};
