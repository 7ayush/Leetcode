class Solution {
public:
    bool util(ListNode *head,TreeNode *root)
    {
        if(!head) return true;
        if(head&&root)
        {
            if(head->val==root->val)
                return util(head->next,root->left)||util(head->next,root->right);
            else 
                return false;
        }
        else
            return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if(!root)return false;
        return util(head,root)||isSubPath(head,root->left)||isSubPath(head,root->right);
    }
};
