/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int>m;
    vector<int>vec;
    int sum(TreeNode *root)
    {
        if(!root)return 0;
        int left=sum(root->left);
        int right=sum(root->right);
        m[left+right+root->val]++;
        return left+right+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        int maxAns=0;
        sum(root);
        for(auto i:m)
        {
            if(i.second>maxAns)
            {
                vec.clear();
                vec.push_back(i.first);
                maxAns=max(i.second,maxAns);
            }
            else if(i.second==maxAns)
            {
                vec.push_back(i.first);
            }
        }
        return vec;
    }
};
