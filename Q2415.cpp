class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())        
        {
            int x=q.size();
            vector<int>temp;
            vector<TreeNode*>tempTree;
            while(x--)
            {
                auto node=q.front();
                q.pop();
                if(level%2==1) 
                {
                    temp.push_back(node->val);
                    tempTree.push_back(node);
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++)
            {
                tempTree[i]->val=temp[i];
            }
            level++;
        }
        return root;
    }
};
