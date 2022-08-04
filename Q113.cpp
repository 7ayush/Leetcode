class Solution {
public:
    void util(TreeNode *root,int targetSum,vector<int>temp,vector<vector<int>>&ans)
    {
        if(!root)return;
        temp.push_back(root->val);
        
        if(!root->left&&!root->right&&targetSum-root->val==0){
            ans.push_back(temp);
            return;
        }
        util(root->left,targetSum-root->val,temp,ans);
        util(root->right,targetSum-root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        util(root,targetSum,{},ans);
        return ans;
    }
};
