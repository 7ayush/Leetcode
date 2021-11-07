//In this we have created a new function and done standard recursive calls
class Solution {
public:
    TreeNode* util(TreeNode* root1,TreeNode *root2)
    {
        TreeNode *root;
        if(!root1&&!root2)return NULL;
        else if(root1&&root2)
        {
            root=new TreeNode(root1->val+root2->val);
            root->left=util(root1->left,root2->left);
            root->right=util(root1->right,root2->right);            
        }
        else if(!root1)
        {
            root=new TreeNode(root2->val);
            root->left=util(NULL,root2->left);
            root->right=util(NULL,root2->right);            
        }
        else
        {
            root=new TreeNode(root1->val);
            root->left=util(root1->left,NULL);
            root->right=util(root1->right,NULL);            
        }
        return root;
        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root=util(root1,root2); 
        return root;
    }
};


//In this we are utilising the given constructors for recursive calls
class Solution {
public:
    TreeNode* util(TreeNode* root1,TreeNode *root2)
    {
        TreeNode *root;
        if(!root1&&!root2)return NULL;
        else if(root1&&root2)
        {
            root=new TreeNode(root1->val+root2->val,util(root1->left,root2->left),util(root1->right,root2->right));      
        }
        else if(!root1)
        {
            root=new TreeNode(root2->val,util(NULL,root2->left),util(NULL,root2->right)); 
                        
        }
        else
        {
            root=new TreeNode(root1->val,util(root1->left,NULL),util(root1->right,NULL)); 
                       
        }
        return root;
        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root=util(root1,root2); 
        return root;
    }
};

//In this we are not creating a util function and are also utilising the given  constructors
class Solution {
public:
     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
     {
         TreeNode* root;
        if(!root1&&!root2)return NULL;
        else if(root1&&root2)
        {
            root=new TreeNode(root1->val+root2->val,mergeTrees(root1->left,root2->left),mergeTrees(root1->right,root2->right));      
        }
        else if(!root1)
        {
            root=new TreeNode(root2->val,mergeTrees(NULL,root2->left),mergeTrees(NULL,root2->right)); 
                        
        }
        else
        {
            root=new TreeNode(root1->val,mergeTrees(root1->left,NULL),mergeTrees(root1->right,NULL)); 
                       
        }
        return root;
    }
};
