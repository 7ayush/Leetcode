class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp=new ListNode(-1);
        temp->next=head;
        head=temp;
        ListNode *ptr=temp;
        while(temp&&temp->next&&temp->next->val<x){
            temp=temp->next;
            ptr=temp;
        }
        while(temp&&temp->next)
        {
            if(temp->next->val<x)
            {
                ListNode *a=temp->next;
                temp->next=a->next;
                a->next=ptr->next;
                ptr->next=a;
                ptr=a;
            }
            else
                temp=temp->next;
        }
        return head->next;
    }
};
