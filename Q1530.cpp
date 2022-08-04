class Solution {
public:
    void util(vector<TreeNode*>temp,TreeNode*root,vector<vector<TreeNode*>>&ans)
    {
        if(!root)return;
        if(root&&!root->left&&!root->right){
            temp.push_back(root);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root);
        util(temp,root->left,ans);
        util(temp,root->right,ans);
    }
    int countPairs(TreeNode* root, int distance) 
    {
        vector<vector<TreeNode*>>paths;
        util({},root,paths);
        int count=0;
        for(int i=0;i<paths.size();i++)
        {
            for(int j=i+1;j<paths.size();j++)
            {
                int p=0,q=0;
                while(paths[i][p]==paths[j][q]){
                    p++;q++;   
                }
                if(paths[i].size()-p+paths[j].size()-q<=distance)count++;
            }
        }
        return count;
    }
};
