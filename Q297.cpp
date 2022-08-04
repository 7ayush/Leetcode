class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        vector<string>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int x=q.size();
            while(x--)
            {
                auto t=q.front();
                q.pop();
                if(!t){
                    ans.push_back("null");
                    continue; 
                }
                ans.push_back(to_string(t->val));
                q.push(t->left);
                q.push(t->right);
            }
            
        }
        string ans1="";
        for(int i=0;i<ans.size();i++)
        {
            ans1+=ans[i];
            if(i!=ans.size()-1)ans1+=',';
        }
        return ans1;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return NULL;
        vector<string>tree;
        string temp="";
        for(char c:data){
            if(c!=',')temp+=c;
            else tree.push_back(temp),temp="";
        }
        if(temp!="")tree.push_back(temp);
        TreeNode *root=new TreeNode(stoi(tree[0]));
        int i=1;
        queue<TreeNode*>q;
        q.push(root);
        while(i<tree.size()&&!q.empty())
        {
            TreeNode *t=q.front();
            q.pop();
            for(int j=0;j<2&&i<tree.size();j++)
            {
                string x=tree[i++];
                TreeNode *temp=x=="null" ? NULL : new TreeNode(stoi(x));
                if(j==0)t->left=temp;
                if(j==1)t->right=temp;
                if(temp!=NULL)q.push(temp);
            }
        }
        return root;    
    }
};
