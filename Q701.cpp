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
    TreeNode* binarySearch(TreeNode *root,int key)
    {
        if(root->val==key)return root;
        else if(root->val>key)
        {
            if(!root->left)return root;
            else
            {
                return binarySearch(root->left,key);
            }
        }
        else 
        {
            if(!root->right)return root;
            else
            {
                return binarySearch(root->right,key);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int key) 
    {
        TreeNode *temp=new TreeNode(key);
        if(!root)return temp;

        TreeNode *node=binarySearch(root,key);
        if(node->val>key)
        {
            temp->left=node->left;
            node->left=temp;
        }
        else if(node->val<key)
        {
            temp->right=node->right;
            node->right=temp;
        }
        return root;
    
    }
};
