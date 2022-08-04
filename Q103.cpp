class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int x=q.size();
            vector<int>temp;
            while(x--)
            {
                TreeNode *t=q.front();                
                q.pop();
                temp.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            if(!flag)reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            flag=!flag;
        }
        return ans;        
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int x=q.size();
            vector<int>temp(x);
            for(int i=0;i<x;i++)
            {
                TreeNode *t=q.front();                
                q.pop();
                if(flag)temp[i]=t->val;
                else temp[x-i-1]=t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            ans.push_back(temp);
            flag=!flag;
        }
        return ans;        
    }
};
