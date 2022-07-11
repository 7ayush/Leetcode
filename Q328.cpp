class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return NULL;
        ListNode *t=head;
        ListNode *x=head->next;
        while(x&&x->next)
        {
            ListNode *temp=x->next;
            x->next=temp->next;
            temp->next=t->next;
            t->next=temp;
            
            t=t->next;
            x=x->next;
        }
        return head;
    }
};
