class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) 
    {
        ListNode *result=NULL;
        if(!a)return b;
        if(!b)return a;
        if(a->val<b->val)
        {
            result=a;
            result->next=mergeTwoLists(a->next,b);
        }
        else
        {
            result=b;
            result->next=mergeTwoLists(a,b->next);
        }
        return result;
    }
};
