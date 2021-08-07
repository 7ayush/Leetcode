//Preorder traversal Node left right

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
    void recursive(TreeNode *root,vector<int>&vec)
    {
        if(root)
        {
            vec.push_back(root->val);
            recursive(root->left,vec);
            recursive(root->right,vec);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>vec;
        recursive(root,vec);
        return vec;
    }
};
