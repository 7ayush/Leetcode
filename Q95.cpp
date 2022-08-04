class Solution {
public:
    vector<TreeNode*> util(int start,int end) {        
        if(start>end)return {NULL};
        vector<TreeNode*>ans;
        for(int i=start;i<=end;i++)
        {
            auto left=util(start,i-1);
            auto right=util(i+1,end);            
            
            for(auto j:left)
            {
                for(auto k:right)
                {                    
                    TreeNode *root=new TreeNode(i);
                    root->left=j;
                    root->right=k;                    
                    ans.push_back(root);
                }                
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {        
        return util(1,n);        
    }
};
