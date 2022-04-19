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
    TreeNode* firstMistake, *secondMistake, *pre;
	void recoverTree(TreeNode* root) {
		pre = new TreeNode(INT_MIN);
		inorder(root);
		swap(firstMistake->val, secondMistake->val);
	}

	void inorder(TreeNode* root) {
		if(root == nullptr) 
			return;

		inorder(root->left);

		if(firstMistake == nullptr && root->val < pre->val)
        {
            cout<<"1 "<<root->val<<" "<<pre->val<<endl;
            firstMistake = pre;
        }
		if(firstMistake != nullptr && root->val < pre->val)
        {
            secondMistake = root;
            cout<<"2 "<<root->val<<" "<<pre->val<<endl;
            
        }			
		pre = root;

		inorder(root->right);
	}
};
