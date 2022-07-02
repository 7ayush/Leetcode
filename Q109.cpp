class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head,ListNode *end=NULL) 
    {
        if(!head||head==end)return NULL;
        if(head->next==end)return new TreeNode(head->val);
        ListNode *slow=head,*fast=head;
        do
        {
            slow=slow->next;
            fast=fast->next->next;
        }while(fast!=end&&fast->next&&fast->next!=end);
        TreeNode *root=new TreeNode(slow->val);
        root->left=sortedListToBST(head,slow);
        root->right=sortedListToBST(slow->next,end);
        return root;
    }
};
